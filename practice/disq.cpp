//14:50
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define LN 20
#define N 100005
#define pii pair<int,int>
vector<vector<pii > > g(N);
int pa[LN+1][N],mxpa[LN+1][N],mnpa[LN+1][N],depth[N];

void dfs(int id=1 ,int prev = 0,int d=0,int cost = 0)
{
	depth[id] = d;
	pa[0][id] = prev;
	mxpa[0][id] = cost;
	mnpa[0][id] = cost;
	for(int i=0;i<g[id].size();i++)
		if(g[id][i].first != prev)
		dfs(g[id][i].first,id,d+1,g[id][i].second);
}

void LCA(int u,int v)
{
	int ansmx = -1000000000,ansmn = 1000000000;
	if(depth[u]<depth[v])
	swap(u,v);
	int diff = depth[u] - depth[v];
	for(int i=0;i<=LN;i++)
		if((diff>>i)&1) {ansmx = max(ansmx,mxpa[i][u]) , ansmn = min(ansmn,mnpa[i][u]) , u = pa[i][u];}
	if(u != v)
	{
		for(int i=LN;i>=0;i--)
			if(pa[i][u] != pa[i][v])
			{
				ansmx = max(ansmx,mxpa[i][u]);
				ansmx = max(ansmx,mxpa[i][v]);
				ansmn = min(ansmn,mnpa[i][u]);
				ansmn = min(ansmn,mnpa[i][v]);
				u = pa[i][u];
				v = pa[i][v];
			}
			ansmx = max(ansmx,mxpa[0][u]);
			ansmx = max(ansmx,mxpa[0][v]);
			ansmn = min(ansmn,mnpa[0][u]);
			ansmn = min(ansmn,mnpa[0][v]);
	}
	printf("%d %d\n",ansmn,ansmx);
}



int main()
{
	int n,u,v,c,k;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d %d %d",&u,&v,&c);
		g[u].pb(mp(v,c));
		g[v].pb(mp(u,c));	
	}
	
	dfs();
	
	// DP
	for(int j=1;j<=LN;j++)
		for(int i=1;i<=n;i++)
		{
			if(pa[j-1][i] !=0)
			{
				pa[j][i] = pa[j-1][pa[j-1][i]];
				mxpa[j][i] = max(mxpa[j-1][i],mxpa[j-1][pa[j-1][i]]);
				mnpa[j][i] = min(mnpa[j-1][i],mnpa[j-1][pa[j-1][i]]);
			}
		}
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d %d",&u,&v);
		LCA(u,v);
	}
}
