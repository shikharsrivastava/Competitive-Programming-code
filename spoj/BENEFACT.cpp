//18:31
#include<bits.stdc++.h>
using namespace std;
#define pii pair<int,int>

vector<vector<pii > >g(50001);
bool vis[50001];
int d=0,nd=0;
void dfs(int id,int depth)
{
	if(vis[id])
	return;
	vis[id]=true;
	if(depth > d)
	{
		d=depth;
		nd=id;	
	}
	for(int i=0;i<g[id].size();i++)
	dfs(g[u][i],depth+1);
}
int main()
{
	int t,n,u,v,w;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(inti =0;i<=n;i++)
		}
	}
}
