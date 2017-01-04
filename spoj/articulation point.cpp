//13:18
#include<bits/stdc++.h>
using namespace std;
vector<vector<int > > g(10001);
int tin[10001],tup[10001],t;
set<int> artpoint;
void dfs(int id,int p)
{
	tin[id] = tup[id] = t++;
	int disconnected_children = 0;
	for(int i=0;i<g[id].size();i++)
	{
		int to = g[id][i];
		if(to != p)
		{
			if(tin[to] >0)
				tup[id] = min(tup[id],tin[to]);
			
			else
			{
			disconnected_children++;
			dfs(to,id);
			tup[id] = min(tup[id],tup[to]);
			if(tup[to] >= tin[id] && p != -1)
			artpoint.insert(id);
			}
		
		}
	}
	if(p == -1 && disconnected_children >1)
	artpoint.insert(id);
	
}
int main()
{
	int n,m,u,v;
	scanf("%d %d",&n,&m);
	while(n+m >0)
	{
		artpoint.clear();
		t = 1;
		for(int i=0;i<=n;i++)
		{
			g[i].clear();
			tin[i] = tin[i] = 0;		
		}

		for(int i=0;i<m;i++)
		{
			scanf("%d %d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
	
		}
		dfs(1,-1);
		printf("%d\n",(int)artpoint.size());
		scanf("%d %d",&n,&m);	
	}
}
