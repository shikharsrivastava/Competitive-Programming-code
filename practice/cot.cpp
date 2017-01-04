/*
	Persistent segment tree 
*/
#include<bits/stdc++.h>
using namespace std;

#define N 100005
#define pb(a) push_back(a)
#define LN 20
vector<vector<int> > g(N);
int root[N],w[N],cmp[N],to[N],depth[N],pa[LN+1][N];
int sz;
int cnt = 0;
int scanint()
{
	register int num = 0;
	char c = getchar_unlocked();
	while(c>='0' && c<='9')
	{
		num = num*10 + c - '0';
		c = getchar_unlocked();
	}
	return num;
}
struct node
{
	int sum;
	int lchild;
	int rchild;
} st[40*N];

int build(int s= 1,int e=sz)
{
	int id = cnt++;
	st[id].sum = 0;
	st[id].lchild = 0;
	st[id].rchild = 0;
	if(s == e)
	return id;
	else
	{
		int m = (s+e)>>1;
		st[id].lchild = build(s,m);
		st[id].rchild = build(m+1,e);
	}	
	return id;
}

int update(int pos,int prev ,int s=1,int e=sz)
{
	int id = cnt++;
	st[id].lchild = st[prev].lchild;
	st[id].rchild = st[prev].rchild;
	st[id].sum = st[prev].sum+1;
	if(s==e)
	return id;
	int m = (s+e)>>1;
	if(pos <= m)
	st[id].lchild = update(pos,st[prev].lchild,s,m);
	else
	st[id].rchild = update(pos,st[prev].rchild,m+1,e);
	return id;
}

struct cocmp
{
	int wt,id;
} so[N];

bool func(const cocmp &a, const cocmp &b)
{
	if(a.wt == b.wt)
		return a.id<b.id;
	return a.wt<b.wt;
}

int LCA(int u,int v)
{
	if(depth[u]<depth[v])
	swap(u,v);
	int diff = depth[u] - depth[v];
	for(int i=0;i<=LN;i++)
		if((diff>>i) &1) u = pa[i][u];
	if(u == v)
	return u;
	for(int i=LN;i>=0;i--)
		if(pa[i][u] != pa[i][v])
		{
			u = pa[i][u];
			v = pa[i][v];
		}
	return pa[0][v];
}

void dfs(int id=1,int prev =0,int prevroot = 0 ,int d = 0)
{
	pa[0][id] = prev;
	depth[id] = d;
	root[id] = update(to[id],prevroot);

	for(int i=0;i<g[id].size();i++)
		if(g[id][i] != prev) dfs(g[id][i],id,root[id],d+1); 
}

int kth(int uroot,int vroot,int lca,int lcap,int k,int s=1,int e=sz)
{
	if(s == e)
	return s;
	
	int m =(s+e)>>1;
	int diff = st[st[uroot].lchild].sum + st[st[vroot].lchild].sum - st[st[lca].lchild].sum - st[st[lcap].lchild].sum;
	if(diff >=k)
	return kth(st[uroot].lchild,st[vroot].lchild,st[lca].lchild,st[lcap].lchild,k,s,m);
	else
	return kth(st[uroot].rchild,st[vroot].rchild,st[lca].rchild,st[lcap].rchild,k-diff,m+1,e);
}

int getans(int u,int v,int k)
{
	int lca = LCA(u,v);
	int lcap = pa[0][lca];
	return kth(root[u],root[v],root[lca],root[lcap],k);
}

int main()
{
	int n,m,u,v,k;
	n = scanint();
	m = scanint();
	for(int i=1;i<=n;i++)
		{w[i] = scanint();so[i].wt = w[i];so[i].id = i;}
	
	// coordinate compression	
	sort(so+1,so+n+1,func);

	for(int i=1;i<=n;)
	{	
		int val = so[i].wt;
		cmp[++sz] = val;
		while(i<=n && so[i].wt == val)
		to[so[i].id] = sz , i++;
			
	}
	
	for(int i=1;i<n;i++)
	{
		u = scanint();
		v = scanint();
		g[u].pb(v);
		g[v].pb(u);
	}


	root[0] = build();
	dfs();
	
	for(int j=1;j<=LN;j++)
		for(int i=0;i<=N;i++)
			if(pa[j-1][i] != 0)
				pa[j][i] = pa[j-1][pa[j-1][i]];
	for(int i=1;i<=m;i++)
	{
		u = scanint();
		v = scanint();
		k = scanint();
		printf("%d\n",cmp[getans(u,v,k)]);
	}
		
}
