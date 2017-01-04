//18:49


#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define LN 14
#define N 10004
vector<vector<pii > > g(N);
int pa[LN+1][N] , depth[N] , dist[N];

void dfs(int id =1 , int prev = 0 ,int d =0,int ds= 0)
{
	pa[0][id] = prev;
	depth[id] = d;
	dist[id] = ds;
	for(int i=0;i<g[id].size();i++)
	{
		int to = g[id][i].first;
		if(to != prev)
		dfs(to,id,d+1,ds+g[id][i].second);
	}
}

int LCA(int u,int v)
{
	if(depth[u] < depth[v])
	swap(u,v);
	
	int diff = depth[u] - depth[v];
	for(int i=0;i<=LN;i++)
		if((diff >> i) &1) u = pa[i][u];
	
	if(u == v)
	return v;
		
	for(int i = LN ;i >=0 ;i--)
		if(pa[i][u] != pa[i][v])
		{
			u = pa[i][u];
			v = pa[i][v];
		}
	return pa[0][u];
}

int getsum(int u,int v)
{
	int lca = LCA(u,v);
	return dist[u] + dist[v] - 2*dist[lca];
}

int kthnum(int u,int v,int k)
{
	int lca = LCA(u,v);
	int lft = depth[u] - depth[lca] + 1;
	if(lft == k)
	return lca;
	else if(lft > k)
	{
		int diff = k-1;
		for(int i=0;i<=LN;i++)
			if((diff >> i) &1) u = pa[i][u];
		return u;
	}
	else
	{
		int total = lft + depth[v] - depth[lca];
		k = total - k +1;
		int diff = k-1;
		for(int i=0;i<=LN;i++)
			if((diff >> i) &1) v = pa[i][v];
		return v;
	}
}

int main()
{
	int t,n,u,v,c,k;
	char ch[100];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=LN;j++)
				pa[j][i] = -1;
			depth[i] = dist[i] = 0;
			g[i].clear();
		}

		for(int i=1;i<n;i++)
		{
			scanf("%d %d %d",&u,&v,&c);
			g[u].push_back(mp(v,c));
			g[v].push_back(mp(u,c));
		}
		dfs();
		
		for(int j=1;j<=LN;j++)
			for(int i=1;i<=n;i++)
				if(pa[j-1][i] != -1)
					pa[j][i] = pa[j-1][pa[j-1][i]];

		while(1)
		{
			scanf("%s",ch);
			if(ch[1] == 'O')
			break;
			else if(ch[1] == 'I')
			{
				scanf("%d %d",&u,&v);
				printf("%d\n",getsum(u,v));
			}
			else
			{
				scanf("%d %d %d",&u,&v,&k);
				printf("%d\n",kthnum(u,v,k));
			}
		}
	}
}
