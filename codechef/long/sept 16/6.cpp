#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long int lli;
lli ans = 0;
int n;
bool ticket[100005];
vector<vector<int > > price(100005);
vector<vector<int > > range(100005);
vector<vector<int > > g(100005);
bool node[10000];
lli st[400005];

void insert(int p,lli val,int s=1,int e=n,int id=1)
{
	if(s == e)
		st[id] = val;
	else
	{
		int m = (s+e)>>1;
		if(p<=m)
			insert(p,val,s,m,id*2);
		else
			insert(p,val,m+1,e,id*2+1);
		st[id] = min(st[id*2],st[id*2+1]);
	}
}

lli get(int l,int r,int s=1,int e=n,int id=1)
{
	if(s>r || e<l)
		return LLONG_MAX;
	else if(s>=l && e<=r)
		return st[id];
	else
	{
		int m = (s+e)>>1;
		lli lft = get(l,r,s,m,id*2);
		lli rgt = get(l,r,m+1,e,id*2+1);
		return min(lft,rgt);
	}
}

void findans(int id = 1,int pa = 0,int d = n)
{
	
	lli mn = LLONG_MAX;
	if(ticket[id])
	{
		for(int i=0;i<range[id].size();i++)
		{
			int end = min(n,d+range[id][i]);
			int start = min(d+1,n);
			lli ans = price[id][i] + get(start,end);
			mn = min(mn,ans);
		}
	}
	
	if(node[id])
		{printf("For %d, ans = %d\n",id,mn);ans += mn;}
	insert(d,mn);
	for(int i=0;i<g[id].size();i++)
		if(g[id][i] != pa)
			findans(g[id][i],id,d-1);
	
	insert(d,0);
}
int main()
{
	int m,u,v,w,k,q;
	scanf("%d %d",&n,&m);
	for(int i=1;i<n;i++)
	{scanf("%d %d",&u,&v);g[u].pb(v);g[v].pb(u);}
	for(int i=1;i<=m;i++)
	{	
		scanf("%d %d %d",&v,&k,&w);
		ticket[v] = true;
		range[v].pb(k);
		price[v].pb(w);
	}

	ticket[1] = true;
	range[1].pb(0);
	price[1].pb(0);

	scanf("%d",&q);
	while(q--)
	{scanf("%d",&u);node[u] = true;}
	findans();
	printf("%lld\n",ans);	
}
