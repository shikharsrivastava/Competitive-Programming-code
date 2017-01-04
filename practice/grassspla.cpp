//12:46
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define N 100005
#define LN 17
vector<vector<int> > g(N);
int depth[N],pa[LN+1][N],chainHead[N],chainId[N],st[4*N],subsize[N],pos[N],lazy[4*N];
int ptr = 0,chainNo = 1;

void dolazy(int id,int s,int e)
{
	st[id] += lazy[id]*(e-s+1);
	if(s<e)
	{ lazy[id*2] += lazy[id];lazy[id*2+1] += lazy[id];}
	lazy[id] = 0;
	return;
}
void setlazy(int id,int s,int e)
{
	lazy[id*2] +=1;
	lazy[id*2+1] +=1;
	return;
}
int LCA(int u,int v)
{
	if(depth[u]<depth[v])
	swap(u,v);
	int diff = depth[u]-depth[v];
	for(int i =0;i<=LN;i++)
		if((diff>>i) &1)  u = pa[i][u];
	if(u == v)
	return u;

	for(int i=LN;i>=0 ;i--)
		if(pa[i][u] != pa[i][v])
		{
			u = pa[i][u];
			v = pa[i][v];
		}
	return pa[0][u];
}

void dfs(int id =1,int prev =0,int d=0)
{
	pa[0][id] = prev;
	depth[id] = d;
	subsize[id] = 1;
	for(int i=0;i<g[id].size();i++)
		if(g[id][i] != prev)
			dfs(g[id][i],id,d+1) , subsize[id] += subsize[g[id][i]];
}

void HLD(int id=1,int prev=0)
{
	if(chainHead[chainNo] == 0)
		chainHead[chainNo] = id;
	chainId[id] = chainNo;
	ptr++;
	pos[id] = ptr;
	int sc = -1;
	for(int i=0;i<g[id].size();i++)
		if(g[id][i] != prev)
			if(sc == -1 || subsize[sc] < subsize[g[id][i]])
				sc = g[id][i];
	if(sc != -1)
	HLD(sc,id);
	
	for(int i=0;i<g[id].size();i++)
		if(g[id][i] != prev && g[id][i] != sc)
			chainNo +=1 , HLD(g[id][i],id);
}

int getsum(int l,int r,int s=1,int e = ptr,int id=1)
{
	if(lazy[id])
	dolazy(id,s,e);

	if(s>r || e<l)
	return 0;
	else if(s>=l && e<=r)
	return st[id];
	else
	{
		int m = (s+e)>>1;
		return getsum(l,r,s,m,id*2) + getsum(l,r,m+1,e,id*2+1);
	}
}

void update(int l,int r,int s=1,int e =ptr,int id=1)
{
	if(lazy[id])
	dolazy(id,s,e);

	if(s>r || e<l)
	return;
	else if(s>=l && e<=r)
	{
		st[id] += (e-s+1);
		if(s<e)
		setlazy(id,s,e);
	}
	else
	{
		int m = (s+e)>>1;
		update(l,r,s,m,id*2);
		update(l,r,m+1,e,id*2+1);
		st[id] = st[id*2] + st[id*2+1];
	}	
}

int query_up(int u,int v)
{
	int uchain,vchain = chainId[v],ans =0;
	while(1)
	{
		uchain = chainId[u];
		if(uchain == vchain)
		{
			if(u == v)
			return ans;
			ans += getsum(pos[v]+1,pos[u]);
			return ans;
		}
		else
		{
			ans += getsum(pos[chainHead[uchain]] , pos[u]);
			u = pa[0][chainHead[uchain]];
		}
	}
}

void updatepast(int u,int v)
{
	int uchain,vchain = chainId[v];
	while(1)
	{
		uchain = chainId[u];
		if(uchain == vchain)
		{
			if(u == v)
			return;
			update(pos[v]+1,pos[u]);
			return;
		}
		else
		{
			update(pos[chainHead[uchain]] , pos[u]);
			u = pa[0][chainHead[uchain]];
		}
	}
}

void plant(int u,int v)
{	
	int lca = LCA(u,v);
	updatepast(u,lca);
	updatepast(v,lca);
}
int query(int u,int v)
{
	int lca = LCA(u,v);
	return query_up(u,lca) + query_up(v,lca);
}

int main()
{
	int n,m,u,v;
	char c;
	scanf("%d %d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		g[u].pb(v);
		g[v].pb(u);
	}	
	dfs();
	HLD();
	// LCA DP
	for(int j=1;j<=LN;j++)
		for(int i=1;i<=n;i++)
			if(pa[j-1][i] != 0)
				pa[j][i] = pa[j-1][pa[j-1][i]];

	for(int i=1;i<=m;i++)
	{
		scanf(" %c %d %d",&c,&u,&v);
		if(c == 'P')
		plant(u,v);	
		else
		printf("%d\n",query(u,v));
	}
}
