//13:18
#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define LN 17
#define pb push_back
int root[N],w[N],depth[N],pa[LN+1][N],to[N],d[N];
vector<vector<int > > g(N);
int sz,ptr;
struct node
{
	int l;
	int r;
	int sum;
} st[40*N];
int build(int s=1,int e=sz)
{
	int id = ++ptr;
	st[id].sum = 0;
	st[id].l = st[id].r = 0;
	if(s == e)
	return id;
	int m = (s+e)>>1;
	st[id].l = build(s,m);
	st[id].r = build(m+1,e);
	return id;
}

int update(int p,int prev,int s =1,int e = sz)
{
	int id = ++ptr;
	st[id].sum = st[prev].sum+1;
	st[id].l = st[prev].l;
	st[id].r = st[prev].r;
	if(s == e)
	return id;
	int m = (s+e)>>1;
	if(p<=m)
	st[id].l = update(p,st[prev].l,s,m);
	else
	st[id].r = update(p,st[prev].r,m+1,e);
	return id;
}
int get(int id,int p,int s=1,int e =sz)
{
	if(s == e)
	return st[id].sum;
	int m = (s+e)>>1;
	if(p<=m)
	return get(st[id].l,p,s,m);
	else
	return get(st[id].r,p,m+1,e);
}

int dfs(int id = 1,int prev = 0,int d=0)
{
	pa[0][id] = prev;
	depth[id] = d;
	root[id] = update(to[id],root[prev]);
	for(int i=0;i<g[id].size();i++)
		if(g[id][i] != prev)
			dfs(g[id][i],id,d+1);
}
int LCA(int u,int v)
{
	if(depth[u] < depth[v])
	swap(u,v);
	int diff = depth[u] - depth[v];
	for(int i=0;i<=LN;i++)
		if((diff >>i) &1) u = pa[i][u];
		
	if(u == v)
	return u;
	for(int i=LN;i>=0;i--)
		if(pa[i][u] != pa[i][v])
		{
			u = pa[i][u];
			v = pa[i][v];
		}
	return pa[0][u];
}
int query(int u,int v,int k)
{
	int pos = lower_bound(d+1,d+sz+1,k) - d;
	if(pos == sz+1 || d[pos] != k)
	return 0;
	int lca = LCA(u,v);
	int f1 = get(root[u],pos);
	int f2 = get(root[v],pos);
	int f3 = get(root[lca],pos);
	int f4 = get(root[pa[0][lca]],pos);
	return (f1+f2-f3-f4);
}
int main()
{
	int n,m,u,v,k;
	while(scanf("%d %d",&n,&m) != EOF)
	{
		ptr = 0;
		for(int i=0;i<=n;i++)
		{
			g[i].clear();
			for(int j=0;j<=LN;j++)
				pa[j][i] = 0;
			depth[i] = 0;
			root[i] = 0;
		}
		for(int i=1;i<=n;i++)
		{scanf("%d",&w[i]);d[i] = w[i];}
		for(int i=1;i<n;i++)
		{
			scanf("%d %d",&u,&v);
			g[u].pb(v);
			g[v].pb(u);
		}
		// coordinate compression
		sort(d+1,d+n+1);
		sz = unique(d+1,d+n+1) - (d+1);
		for(int i=1;i<=n;i++) to[i] = lower_bound(d+1,d+sz+1,w[i]) - d;
		
		root[0] = build();
		dfs();
		// LCA dp
		for(int j=1;j<=LN;j++)
			for(int i =1;i<=n;i++)
				if(pa[j-1][i] != 0)
				pa[j][i] = pa[j-1][pa[j-1][i]];
		for(int i=1;i<=m;i++)
		{
			scanf("%d %d %d",&u,&v,&k);
			if(query(u,v,k))
			printf("Find\n");
			else
			printf("NotFind\n");
		}
		printf("\n");
	}
}
