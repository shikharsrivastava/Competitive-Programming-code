#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
typedef long long lli;
int c[100005];
int st[400005];
int n;
void build(int s =1,int e=n,int id=1)
{
	if(s == e)
	{
		st[id] = 1<<(c[s]);
		return ;
	}
	int m = (s+e)>>1;
	build(s,m,id*2);
	build(m+1,e,id*2+1);
	st[id] = st[id*2]|st[id*2+1];
	return;
}

int canmake(int l,int r,int s=1,int e=n,int id=1)
{
	if(s>r || e<l)
		return 0;
	else if(s>=l && e<=r)
		return st[id];
	else
	{
		int m = (s+e)>>1;
		return canmake(l,r,s,m,id*2) | canmake(l,r,m+1,e,id*2+1);
	}
}

int main()
{
	int t,u,k,q;
	scanf("%d",&t);
	while(t--)
	{
		memset(st,0,sizeof(st));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&c[i]);
		scanf("%d",&q);
		build();
		while(q--)
		{
		
			scanf("%d %d",&u,&k);
			int m = 1<<c[u];
			int s = u,e=u;
			int ans = 0;
			while(__builtin_popcount(m) <k)
			{
				ans++;
				s = s*2;
				e = min(n,e*2+1);
				if(s>n)
					break;
				m = m|canmake(s,e);
			}
			if(__builtin_popcount(m) >=k)
				printf("%d\n",ans);
			else
				printf("-1\n");

		}
	
	}
}
