//23:05
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define LN 18
vector<vector<int> > g(100002);
int depth[100005],pa[LN+1][1000005];
int a[100004];

inline int scanint()
{
	register int num =0;
	char c = getchar_unlocked();
	while(c >='0' && c<= '9')
	{
		num = num * 10 + c - '0';
		c = getchar_unlocked();
	}
	return num;
}

void dfs(int id,int p,int d)
{
	depth[id] = d;
	pa[0][id] = p;
	for(int i = 0;i<g[id].size();i++)
	if(g[id][i] != p)
	dfs(g[id][i],id,d+1);
}
int LCA(int u,int v)
{
	if(depth[u] < depth[v])
		swap(u,v);
	int diff = depth[u] - depth[v];	
	for(int i=0;i<=LN;i++)
		if((diff>>i)&1)
				u = pa[i][u];
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

void extract(int u,int v,int lca,int *arr,int len)
{
	int ptr = 1;
	while(1)
	{
		arr[ptr++] = a[u];
		if(u == lca)
			break;
		u = pa[0][u];
	}
	while(v != lca)
		arr[len--] = a[v] , v = pa[0][v];
}

void reverse(int u,int v)
{
	int lca = LCA(u,v);
	int len = depth[u] + depth[v] - 2*depth[lca] +1;
	int arr[len+1];
	// Extracing
	extract(v,u,lca,arr,len);
		
	// Copying
	int ptr = 1;
	while(1)
	{
		a[u] = arr[ptr++];
		if(u == lca)
			break;
		u = pa[0][u];
	}
	while(v != lca)
		a[v] = arr[len--] , v = pa[0][v];
}

bool same(int u1,int v1,int u2,int v2)
{
	int lca1 = LCA(u1,v1);
	int lca2 = LCA(u2,v2);
	int len = depth[u1] + depth[v1] - 2*depth[lca1] +1;

	int arr1[len+1],arr2[len+1];
	
	extract(u1,v1,lca1,arr1,len);
	extract(u2,v2,lca2,arr2,len);
	
	for(int i=1;i<=len;i++)
	if(arr1[i] != arr2[i])
		return false;
	return true;
	
}

void copypath(int u1,int v1,int u2,int v2)
{
	int lca1 = LCA(u1,v1);
	int lca2 = LCA(u2,v2);
	int len = depth[u1] + depth[v1] - 2*depth[lca1] +1;
	int arr[len+1];
	extract(u1,v1,lca1,arr,len);
	
	int ptr = 1;
	while(1)
	{
		a[u2] = arr[ptr++];
		if(u2 == lca2)
			break;
		u2 = pa[0][u2];
	}
	while(v2 != lca2)
		a[v2] = arr[len--] , v2 = pa[0][v2];
	
}

int main()
{
	int c,q,n,u,v;
	for(int j=0;j<=LN;j++)
		for(int i=1;i<=n;i++)
			pa[j][i] = -1;
	n = scanint();
	q = scanint();
	for(int i=1;i<=n;i++)
	a[i] = scanint();
	
	for(int i=1;i<n;i++)
	{
		u = scanint();
		v = scanint();
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1,0,1);
	//LCA dp
	for(int j=1;j<=LN;j++)
		for(int i=1;i<=n;i++)
			if(pa[j-1][i] != -1)
				pa[j][i] = pa[j-1][pa[j-1][i]];


	int u1,v1,u2,v2;	
	while(q--)
	{
		c = scanint();
		if(c == 1)
		{
			u = scanint();
			v = scanint();
			reverse(u,v);
		}
		else 
		{
			u1 = scanint();
			v1 = scanint();
			u2 = scanint();
			v2 = scanint();
			if(c == 2)
			{	
				if(same(u1,v1,u2,v2))
					printf("Yes\n");
				else
					printf("No\n");
			}
			else
				copypath(u1,v1,u2,v2);
		
			
		}
	 }
}
