// 14:05
#include<bits/stdc++.h>
using namespace std;
#define N 300005
#define LN 20
#define pb push_back
vector<vector<int > > g(N);
int depth[N],arr[N],subsize[N],pos[N],chainId[N],chainHead[N],pa[LN+1][N],p[N],st[4*N];
bool vis[N],visHLD[N];
int ptr = 0 , chainNo = 0;
struct st
{
	int parent;
	int rank;
} Set[N];

void make_set(int s)
{
	Set[s].parent = s;
	Set[s].rank = 0;
}

int find_set(int s)
{
	if(Set[s].parent == s)
	return s;
	Set[s].parent = find_set(Set[s].parent);
	return Set[s].parent;	
}

void union_set(int a,int b)
{
	a = find_set(a);
	b = find_set(b);
	if(a == b)
	return;
	if(Set[a].rank < Set[b].rank)
	swap(a,b);
	Set[b].parent = a;
	if(Set[a].rank == Set[b].rank)
	Set[a].rank++;
	return;
}

struct Q
{
	int u,v,ans;
	char c;
} q[N];

void dfs(int id,int prev,int d =0)
{
	vis[id] = true;
	depth[id] = d;
	subsize[id] = 1;
	pa[0][id] = prev;
	for(int i=0;i<g[id].size();i++)
		if(g[id][i] != prev)
			dfs(g[id][i],id,d+1) , subsize[id] += subsize[g[id][i]];
}

void HLD(int id,int prev,int cost)
{
	visHLD[id] = true;
	if(chainHead[chainNo] == 0)
		chainHead[chainNo] = id;
	ptr++;
	arr[ptr] = cost;
	pos[id] = ptr;
	chainId[id] = chainNo;
	
	int sc = -1 , ncost = 0;
	for(int i=0;i<g[id].size();i++)
		if(g[id][i] != prev)
			if(sc == -1 || subsize[sc] < subsize[g[id][i]])
				sc = g[id][i] , ncost = p[g[id][i]];
	if(sc != -1)
	HLD(sc,id,ncost);
	
	for(int i=0;i<g[id].size();i++)
		if(g[id][i] != prev && g[id][i] != sc)
			chainNo++ , HLD(g[id][i],id,p[g[id][i]]);
}

void build(int s =1 ,int e =ptr ,int id =1)
{
	if(s == e)
	{st[id] = arr[s] ; return;}
	int m = (s+e)>>1;
	build(s,m,id*2);
	build(m+1,e,id*2+1);
	st[id] = st[id*2] + st[id*2+1];
	return;	
}

void update(int ind,int s =1,int e = ptr,int id=1)
{
	if(s == e)
	{st[id] = arr[ind] ; return;}
	int m = (s+e)>>1;
	if(ind <= m)
	update(ind,s,m,id*2);
	else
	update(ind,m+1,e,id*2+1);
	st[id] = st[id*2] + st[id*2+1];
}
int getsum(int l,int r,int s=1,int e=ptr,int id =1)
{
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
int LCA(int u,int v)
{

	if(depth[u] < depth[v])
	swap(u,v);
	int diff = depth[u] - depth[v];
	for(int i=0;i<=LN;i++)
		if((diff >> i) &1)	u = pa[i][u];
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

int query_up(int u,int v)
{
	int uchain , vchain = chainId[v],ans =0;
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
			ans += getsum(pos[chainHead[uchain]],pos[u]);
			u = pa[0][chainHead[uchain]];
		}
	}
}

int pengu(int u,int v)
{
	if(u == v)
	return arr[pos[u]];
	int lca = LCA(u,v);
	return query_up(u,lca) + query_up(v,lca) + arr[pos[lca]];
}
int main()
{
	int n,m,u,v;
	char s[20];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{scanf("%d",&p[i]);make_set(i);}
	scanf("%d",&m);
	
	for(int i=1;i<=m;i++)
	{
		scanf("%s %d %d",s,&u,&v);
		q[i].u = u , q[i].v = v , q[i].c = s[0];

		if(q[i].c == 'b')
		{
			if(find_set(u) != find_set(v))
			{
				q[i].ans = 1 , union_set(u,v);
				g[u].pb(v);
				g[v].pb(u);
			}
			else
			q[i].ans = 0;
		}
		else if(q[i].c == 'e')
		{
			if(find_set(u) == find_set(v))
			q[i].ans = 1;
			else
			q[i].ans = 0;
		}
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs(i,0);

	
	for(int i=1;i<=n;i++)
		if(!visHLD[i])
			chainNo++,HLD(i,0,p[i]);
	build();
	// LCA DP
	for(int j=1;j<=LN;j++)
		for(int i=1;i<=n;i++)
			if(pa[j-1][i] != 0)
				pa[j][i] = pa[j-1][pa[j-1][i]];
	for(int i=1;i<=m;i++)
	{
		if(q[i].c == 'b')
		q[i].ans == 1 ? printf("yes\n") : printf("no\n");
		else if(q[i].c == 'e')
		q[i].ans == 1 ? printf("%d\n",pengu(q[i].u,q[i].v)) : printf("impossible\n");
		else if(q[i].c == 'p')
		{
		arr[pos[q[i].u]] = q[i].v;
		update(pos[q[i].u]);
		}
	}	
}

