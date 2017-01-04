//20:32
#include<bits/stdc++.h>
using namespace std;
#define N 100000
#define LN 20
#define pb push_back

vector<vector<int > > g(N);
int w[N],pa[LN+1][N],arr[2*N],depth[N];
int l[N],r[N],bl[N],BS,nodeHash[N],valHash[N],ans[N],d[N],to[N];
int ptr = 0,res=0;

void dfs(int id=1,int prev = 0,int d=0)
{
	depth[id] = d;
	pa[0][id] = prev;
	ptr++;
	l[id] = ptr;
	arr[ptr] = id;
	for(int i=0;i<g[id].size();i++)
		if(g[id][i] != prev)
			dfs(g[id][i],id,d+1);
	ptr++;
	r[id] = ptr;
	arr[ptr] = id;
}

int LCA(int u,int v)
{
	if(depth[u] < depth[v])
		swap(u,v);
	int diff = depth[u]- depth[v];
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
struct query
{
	int l,r,lca,id;
} q[N];
bool cp(const query &a, const query &b)
{
	if(bl[a.l] == bl[b.l])
		return a.r < b.r;
	return bl[a.l] < bl[b.l];
}

void check(int id)
{

	if(nodeHash[id] && (--valHash[to[id]] == 0))
			res--;
	else if((!nodeHash[id]) && (++valHash[to[id]] == 1))
			res++;
	nodeHash[id] ^= 1;
}
int main()
{
	int n,m,u,v,c;
	scanf("%d %d",&n,&m);
	
	
	for(int i=1;i<=n;i++)
		{scanf("%d",&w[i]);d[i] = w[i];}
	
	sort(d+1,d+n+1);

	int sz = unique(d+1,d+n+1) - (d+1);

	for(int i=1;i<=n;i++)
		to[i] = lower_bound(d+1,d+sz+1,w[i]) - d;

	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		g[u].pb(v);
		g[v].pb(u);
	}
	// Flattening tree
	dfs();
	// Creating blocks
	BS = sqrt(ptr);
	for(int i=1;i<=ptr;i++)
		bl[i] = (i-1)/BS + 1;
	// LCA DP
	for(int j=1;j<=LN;j++)
		for(int i=1;i<=n;i++)
			if(pa[j-1][i] != 0)	pa[j][i] = pa[j-1][pa[j-1][i]];
	// Storing queries
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		if(l[u] > l[v])
		swap(u,v);
		q[i].id = i;
		q[i].lca = LCA(u,v);
		if(q[i].lca == u)
			q[i].l = l[u] , q[i].r = l[v];
		else
			q[i].l = r[u] , q[i].r = l[v];
	}


	// Sorting in mos order
	sort(q+1,q+m+1,cp);
	
	//Mo's algorithm
	int lft = q[1].l , rgt = q[1].l -1;
	res = 0;
	for(int i=1;i<=m;i++)
	{
		while(rgt<q[i].r)
			rgt++,check(arr[rgt]);
		while(rgt>q[i].r)
			check(arr[rgt]),rgt--;
		while(lft < q[i].l)
			check(arr[lft]),lft++;
		while(lft>q[i].l)
			lft--,check(arr[lft]);
		if(q[i].lca != arr[q[i].l] && q[i].lca != arr[q[i].r])
				check(q[i].lca);
		ans[q[i].id] = res;
		if(q[i].lca != arr[q[i].l] && q[i].lca != arr[q[i].r])
				check(q[i].lca);
	}
	for(int i=1;i<=m;i++)
	printf("%d\n",ans[i]);
	return 0;
}
