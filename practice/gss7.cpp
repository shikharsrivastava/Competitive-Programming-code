//12:38
#include<bits/stdc++.h>
using namespace std;
#define LN 20
#define N 100005
/*
	Heavy light decomposition with segment tree supporting range update and range query
*/
int depth[N],chainHead[N],subsize[N],chainInd[N],pa[LN+1][N],arr[N],pos[N],x[N];
vector<vector<int > > g(N+2);
int chainNo = 0,ptr = 1;

struct node
{
	int ans;
	int sum;
	int left;
	int right;
	bool lazy;
	int val;
	
} st[N*4];

void dolazy(int id,int s,int e)
{
	st[id].lazy = false;
	st[id].sum = (e-s+1)*st[id].val;
	if(st[id].val >=0)
	st[id].left = st[id].right = st[id].ans = st[id].sum;
	else
	st[id].left = st[id].right = st[id].ans = st[id].val;
	
	if(s!=e)
	{
		st[id*2].lazy = st[id*2+1].lazy = true;
		st[id*2].val = st[id*2+1].val = st[id].val;
	}
}

void merge(node &ret , node lft, node rgt)
{
	ret.lazy = lft.lazy | rgt.lazy;
	ret.sum = lft.sum+rgt.sum;
	ret.left = max(lft.left,lft.sum+rgt.left);
	ret.right = max(rgt.right , rgt.sum+lft.right);
	ret.ans = max(lft.ans,max(rgt.ans,lft.right+rgt.left));
}
void make(int s=1,int e=ptr-1,int id=1)
{
	st[id].lazy = false;
	if(s == e)
	st[id].sum = st[id].ans = st[id].left = st[id].right = arr[s];
	else
	{
		int m = (s+e)>>1;
		make(s,m,id*2);
		make(m+1,e,id*2+1);
		merge(st[id],st[id*2],st[id*2+1]);
	}
}

node query(int l,int r,int s = 1,int e = ptr-1,int id=1)
{
	if(st[id].lazy)
	dolazy(id,s,e);

	node ret;
	ret.sum = 0;
	ret.lazy = false;
	ret.left = ret.right = ret.ans = -1000000000;
	
	if(s>r || e<l)
	ret;
	else if(s>=l && e<=r)
	return st[id];
	else
	{
		int m = (s+e)>>1;
		node lft = query(l,r,s,m,id*2);
		node rgt = query(l,r,m+1,e,id*2+1);
		merge(ret,lft,rgt);
	}
	return ret;
}

void update(int l,int r,int val,int s=1,int e = ptr-1,int id=1)
{
	if(st[id].lazy)
	dolazy(id,s,e);

	if(s>r || e<l)
	return;
	else if(s>=l && e<=r)
	{	
		st[id].sum = (e-s+1)*val;
		if(val >=0)
		st[id].ans = st[id].left = st[id].right = st[id].sum;
		else
		st[id].ans = st[id].left = st[id].right  = val;
		if(s != e)
		{
			st[id*2].lazy = st[id*2+1].lazy = true;
			st[id*2].val = st[id*2+1].val = val;
		}
	}
	else
	{
		int m = (s+e)>>1;
		update(l,r,val,s,m,id*2);
		update(l,r,val,m+1,e,id*2+1);
		merge(st[id],st[id*2],st[id*2+1]);
	}
}

void dfs(int id =1,int prev = 0,int d =0)
{
	pa[0][id] = prev;
	subsize[id] = 1;
	depth[id] = d;
		
	for(int i=0;i<g[id].size();i++)
	{
		if(g[id][i] == prev) continue;
		dfs(g[id][i],id,d+1);
		subsize[id] += subsize[g[id][i]];
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
	
	for(int i=LN ; i>=0 ;i--)
		if(pa[i][u] != pa[i][v])
		{
			u = pa[i][u];
			v = pa[i][v];	
		}
	return pa[0][v];
}

void HLD(int id = 1,int prev = 0,int cost = x[1])
{
	if(chainHead[chainNo] == 0)
		chainHead[chainNo] = id;
	pos[id] = ptr;
	arr[ptr++] = cost;
	chainInd[id] = chainNo;
	int sc = -1,ncost;
	for(int i=0;i<g[id].size();i++)
	{
		if(g[id][i] == prev) continue;
		if(sc == -1 || subsize[sc] < subsize[g[id][i]])
			sc = g[id][i] , ncost = x[g[id][i]];
	}
	if(sc != -1)
		HLD(sc,id,ncost);
			
	for(int i=0;i<g[id].size();i++)
	{
		if(g[id][i] != prev && g[id][i] != sc)
		{	
			chainNo++;
			HLD(g[id][i],id,x[g[id][i]]);
		}
	}
}

node queryUp(int u,int v)
{
	int uchain,vchain = chainInd[v];
	node ans,ret;
	ans.lazy = false;
	ans.sum = 0;
	ans.left = ans.right = ans.ans = -1000000000;
	while(1)
	{
		uchain = chainInd[u];
		if(uchain == vchain)
		{
			if(u == v)
			break;
			ret = query(pos[v]+1,pos[u]);
			merge(ans,ret,ans);
			return ans;
		}
		else
		{
			ret = query(pos[chainHead[uchain]],pos[u]);
			merge(ans,ret,ans);
			u = chainHead[uchain];
			u = pa[0][u];
		}
	}
	return ans;
}

int qr(int u,int v)
{
	int lca = LCA(u,v);
	node ans,ret;
	ans.lazy = false;
	ans.sum = 0;
	ans.left = ans.right = ans.ans = -1000000000;
	ret = queryUp(u,lca);
	//merging left chain
	merge(ans,ret,ans);
	// merging lca
	ret = query(pos[lca],pos[lca]);
	merge(ans,ret,ans);
	// merging right chain
	ret = queryUp(v,lca);
	swap(ret.left,ret.right);
	merge(ans,ret,ans);
	return ans.ans;
}	

void changeUp(int u,int v,int val)
{
	int uchain ,vchain = chainInd[v];
	while(1)
	{
		uchain = chainInd[u];
		if(uchain == vchain)
		{
			update(pos[v],pos[u],val);
			return;
		}
		else
		{
			update(pos[chainHead[uchain]],pos[u],val);
			u = chainHead[uchain];
			u = pa[0][u];
		}
	}
}

void change(int u,int v,int val)
{
	int lca = LCA(u,v);
	changeUp(u,lca,val);
	changeUp(v,lca,val);
}

int main()
{
	int n,u,v,q,ch,a,b,val,ans;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&x[i]);
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
		for(int j=0;j<=LN;j++)
			pa[j][i] = -1;
	}

	
		dfs();
		HLD();
		make();
		for(int j=1;j<=LN;j++)
		for(int i=1;i<=n;i++)
			if(pa[j-1][i] != -1)
				pa[j][i] = pa[j-1][pa[j-1][i]];
	
	
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&ch);
		if(ch == 1)
		{
			scanf("%d %d",&a,&b);
			ans = qr(a,b);
			if(ans <0)
			printf("0\n");
			else
			printf("%d\n",ans);
		}
		else
		{
			scanf("%d %d %d",&a,&b,&val);
			change(a,b,val);

		}	
	}
	return 0;
}
