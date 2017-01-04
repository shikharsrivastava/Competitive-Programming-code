#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pb push_back
#define mp make_pair
#define pii pair<int,int>

int main()
{
	int n,m,k,u,v,c;
	scanf("%d %d %d",&n,&m,&k);
	vector<vector<pii> > g(n+1);
	bool mark[n+1];
	memset(mark,false,sizeof(mark));
	for(int i =1;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&c);
		g[u].pb(mp(c,v));
		g[v].pb(mp(c,u));
	}
	int mn = 1000000001;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&u);
		mark[u] = true;
	}	
	for(int i=1;i<=n;i++)
		if(mark[i])
			for(int j=0;j<g[i].size();j++)
				if(!mark[g[i][j].second])
					mn = min(mn,g[i][j].first);

		
	if(mn == 1000000001)
		printf("-1\n");
	else 
		printf("%d\n",mn);
	return 0;
}
