//10:32
#include<bits/stdc++.h>
using namespace std;

#define mp(a,b) make_pair(a,b)
#define LN 20
#define pii pair<int,int>

vector<vector<pii > > g(100001);
vector<vector<int > > ind(100001);
int arr[200005];
int pos[100001];
int chainHead[100001];
int chainInd[100001];
int st[400004];
int depth[100001];
int subsize[100001];
int chainNo , ptr;
int pa[LN+1][100001];
int otherEnd[100001];

void make(int s=1,int e=ptr-1,int id=1)
{
	if(s == e)
	st[id] = arr[s];
	else
	{
		int m = (s+e)/2;
		make(s,m,id*2);
		make(m+1,e,id*2+1);
		st[id] = max(st[id*2],st[id*2+1]);
	}
}

void update(int p ,int v ,int s =1 ,int e = ptr-1 , int id =1)
{
	if(s == e)
	st[id] = arr[s] = v;
	else
	{
		int m = (s+e)/2;
		if(p<=m)
		update(p,v,s,m,id*2);
		else
		update(p,v,m+1,e,id*2+1);
		st[id] = max(st[id*2],st[id*2+1]);
	}
}

int qrt(int l,int r,int s =1 ,int e = ptr-1 , int id =1)
{
	
	if(s>r || e<l)
	return 0;
	else if(s >= l && e <= r)
	return st[id];
	else
	{
		int m = (s+e)/2;
		int lm = qrt(l,r,s,m,id*2);
		int rm = qrt(l,r,m+1,e,id*2+1);
		return max(lm,rm);
	}
}

int LCA(int u,int v)
{
	if(depth[u] < depth[v])
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
	return pa[0][u];
}

void dfs(int id,int prev, int d=0)
{
	pa[0][id] = prev;
	depth[id] = d;
	subsize[id] = 1;
	
	for(int i=0;i<g[id].size();i++)
	{
		int to = g[id][i].first;
		if(to != prev)
		{
			otherEnd[ind[id][i]] = to;
			dfs(to,id,d+1);
			subsize[id] += subsize[to];
		}
	} 
}

void HLD(int id,int prev,int cost = 0)
{
	if(chainHead[chainNo] == 0)
		chainHead[chainNo] = id;
	pos[id] = ptr;
	arr[ptr++] = cost;
	chainInd[id] = chainNo; 

	int sc = -1 ,ncost;
	for(int i=0;i<g[id].size();i++)
	{
		int to = g[id][i].first;
		if(to != prev)
		{
			if(sc == -1 || subsize[sc] < subsize[to])
			{sc = to , ncost = g[id][i].second;}
		}
	}
	if(sc != -1)
	HLD(sc,id,ncost);
	
	for(int i=0;i<g[id].size();i++)
	{
		int to = g[id][i].first;
		if(to != prev && to != sc)
		{
			chainNo++;
			HLD(to,id,g[id][i].second);
		}
	}
}

int query_up(int u,int v)
{
	if(u == v)
	return 0;
	int uchain , vchain = chainInd[v] , ans = -1;
	while(1)
	{
		uchain = chainInd[u];
		if(uchain == vchain)
		{
			if(u == v)
			break;
			int temp = qrt(pos[v]+1,pos[u]);
			if(temp >ans)
			ans = temp;
			break;
		}
		else
		{
			int temp = qrt(pos[chainHead[uchain]],pos[u]);
			if(temp >ans)	
			ans = temp;
			u = chainHead[uchain];
			u = pa[0][u];
		}
	}
	return ans;
}

int query(int u,int v)
{
	int lca = LCA(u,v);
	int ans = query_up(u,lca);
	int temp = query_up(v,lca);
	return max(ans,temp);
}

void change(int i , int val)
{
	//printf("Changing %d\n",otherEnd[i]);
	update(pos[otherEnd[i]],val);
}

int main()
{
	int t,n,u,v,c;
	char ch[100];
	scanf("%d",&t);
	while(t--)
	{
		chainNo = 0 , ptr = 1 ;
		scanf("%d",&n);
		for(int i=0;i<=n;i++)
		{
			pos[i] = chainInd[i] = depth[i] = subsize[i] = chainHead[i] = otherEnd[i] = 0;
			g[i].clear();
			ind[i].clear();
			for(int j =0;j<=LN;j++)
				pa[j][i] = -1;					
		}
		for(int i=1;i<n;i++)
		{
			scanf("%d %d %d",&u,&v,&c);
			g[u].push_back(mp(v,c));
			g[v].push_back(mp(u,c));
			ind[u].push_back(i);
			ind[v].push_back(i);
		}
		dfs(1,0);
		HLD(1,0);
		make();
		for(int j=1;j<=LN;j++)
			for(int i=0;i<=n;i++)
				if(pa[j-1][i] != -1)
					pa[j][i] = pa[j-1][pa[j-1][i]];
	
		
		while(1)
		{
			scanf("%s",ch);
			if(ch[0] == 'D')
			break;
			else if(ch[0] == 'C')
			{
				scanf("%d %d",&u,&v);
				change(u,v);
			}
			else if(ch[0] == 'Q')
			{
				scanf("%d %d",&u,&v);
				printf("%d\n",query(u,v));
			} 
		}
	}
	return 0;
}
