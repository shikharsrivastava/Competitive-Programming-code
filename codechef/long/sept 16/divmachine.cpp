//18:13
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int n;
vector<vector<int> > fact(100005);
int indices[100005];
bool vis[1000006];
int st[400005];
int a[100005];

void build(int s=1,int e=n,int id=1)
{
	if(s == e)
	{ st[id] = fact[s][indices[s]];return;}
	else
	{
		int m = (s+e)>>1;
		build(s,m,id*2);
		build(m+1,e,id*2+1);
		st[id] = max(st[id*2],st[id*2+1]);
	}
}

void update(int l,int r,int s=1,int e=n,int id=1)
{
	if(s>r || e<l)
		return;
	if(st[id] == 1)
		return;
	if(s == e)
	{
		indices[s]++;
		st[id] = fact[s][indices[s]]; 
		return;
	}
	else
	{
		int m = (s+e)>>1;
		update(l,r,s,m,id*2);
		update(l,r,m+1,e,id*2+1);
		st[id] = max(st[id*2],st[id*2+1]);
	}
}

int get(int l,int r,int s=1,int e=n,int id=1)
{
	if(s>r || e<l)
		return 0;
	else if(s>=l && e<=r)
	return st[id];
	else
	{
		int m = (s+e)>>1;
		int lf = get(l,r,s,m,id*2);
		int rg = get(l,r,m+1,e,id*2+1);
		return max(lf,rg);
	}
}
int main()
{
	int t,m,l,r,c;
	scanf("%d",&t);
	set<int> primes;
	
	for(int i=2;i<=1000000;i++)
	{
		if(vis[i]) continue;
		primes.insert(i);
		int mul = i;
		while((long long)mul*i<=1000000)
		{
			vis[mul*i] = true;
			mul++;
		}
	}
	while(t--)
	{
		memset(indices,0,sizeof(indices));
		//memset(set1,false,sizeof(set1));

		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++)
			fact[i].clear();

		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		{
			int num = a[i];
			if(primes.find(num) == primes.end())	
			{
				for(int j=2;num>1 && j<=sqrt(a[i])+1;j++)
				while(num % j == 0)
				{	
					fact[i].pb(j);
					num /= j;
				}
			}
			/*if(a[i] == 1)
				set1[i] == true;*/
			fact[i].pb(num);
			fact[i].pb(1);
		}
		build();
			
		while(m--)
		{
			scanf("%d",&c);
			if(c == 0)
			{
				scanf("%d %d",&l,&r);
				update(l,r);
				/*if(get(l,r) != 1)
				{
					for(int i=l;i<=r;i++)
					{
						if(set1[i]) continue;

						update(i);
						if(fact[i][indices[i]] == 1)
							set1[i] = true;					
					}
				}*/
			}
			else if(c == 1)
			{scanf("%d %d",&l,&r);printf("%d\n",get(l,r));}
		}
	}
}
