//22:53
#include<bits/stdc++.h>
#define make_pair(a,b) mp(a,b)
using namespace std;

int c;
bool *vis;
vector<vector<int> > g(10000);

void dfs(int parent,int id,int depth)
{
	if(depth <0)
	return;

	if(!vis[id])
	c++;

	vis[id]=true;

	printf("at node %d ,depth %d c =%d\n",id,depth,c);

	for(int i=0;i<g[id].size();i++)
	{
		if(g[id][i] != parent)
		dfs(id,g[id][i],depth-1);
	}
	
}
int main()
{
	int n,s,t,u,v,cn=0;
	vis=(bool*)calloc(10000,sizeof(bool));
	scanf("%d",&n);
	while(n !=0)
	{

		
	
		g.clear();
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		scanf("%d %d",&s,&t);
		while((s+t) >0)
		{
			for(int i=0;i<10000;i++)
			vis[i]=false;
			c=0;
			cn++;
			dfs(0,s,t);
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d\n",cn,n-c,s,t);
			
		scanf("%d %d",&s,&t);
		}
		scanf("%d",&n);
	}

}
