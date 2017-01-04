//22:05
#include<bits/stdc++.h>
using namespace std;
vector<vector<int > >t(100001);
vector<bool> vis(1000001);
int md,node;
void dfs(int id,int depth)
{
	if(vis[id])
	return;
	vis[id]=true;
	if(depth > md)
	{
		md=depth;
		node=id;
	}
	//printf("id = %d depth = %d md = %d\n",id,depth,md);
	for(int i=0;i<t[id].size();i++)
	dfs(t[id][i],depth+1);
}
int main()
{
	md=0;
	int n,u,v;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d",&u,&v);
		t[u].push_back(v);
		t[v].push_back(u);
	}
	
	for(int i=0;i<=n;i++)
	vis[i]=false;
	dfs(1,0);
	md=0;
	for(int i=0;i<=n;i++)
	vis[i]=false;
	dfs(node,0);
	printf("%d\n",md);
}
