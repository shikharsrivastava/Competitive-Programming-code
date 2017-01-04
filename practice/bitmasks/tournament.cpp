//9:30
#include<bits/stdc++.h>
using namespace std;
int arr[100];
vector<vector<int> > g(100);
bool vis[100];
#define pb push_back
bool path(int id,int v)
{
	if(id == v)
	return true;
	bool ret = false;
	for(int i=0;i<g[id].size();i++)
	if(!vis[g[id][i]])
	vis[g[id][i]]= true , ret |= path(g[id][i],v);
	return ret;
	
}
int main()
{
	int n;
	scanf("%d",&n);
	int u,v;
	for(int i=1;i<=(n*(n-1))/2-1;i++)
	{
		scanf("%d %d",&u,&v);
		g[u].pb(v);
		arr[u]++,arr[v]++;
	}
	
	vector<int> nf;
	for(int i=1;i<=n;i++)
	if(arr[i] != n-1)
		nf.pb(i);
	u = nf[0], v=nf[1];
	
	bool uv = path(u,v);
	memset(vis,false,sizeof(vis));
	bool vu = path(v,u);
	if(uv)
	printf("%d %d\n",u,v);
	else if (vu)
	printf("%d %d\n",v,u);
	else
	printf("%d %d\n",u,v);
	
	
}
