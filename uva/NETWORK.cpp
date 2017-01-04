//21:59
#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > g(100);
bool visited[100];
bool articulate[100];
int tin[100];
int fup[100];
int t = 0;
void dfs(int v,int p=-1)
{
	visited[v]=true;
	tin[v]=fup[v]=t++;
	int child =0;
	for(int i=0;i<g[v].size();i++)
	{
		int to=g[v][i];
		if(to == p)
		continue;
		else
		{
			if(! visited[to])
				dfs(to,v);
				fup[v]=min(fup[v],fup[to]);
			if(fup[to] >= tin[v] && p!= -1)
			articulate[v]=true;
		}
		++child;
	}
	if( p == -1 && child >1)
	{
		printf("v= %d p = %d ,child = %d\n",v,p,child);
		articulate[v] = true;
	}
}
int main()
{	
	int n,u,v,m;
	scanf("%d",&n);
	while(n>0)
	{
		for(int i=0;i<=n;i++)
		{
			g[i].clear();
			articulate[i]=false;
			visited[i]=false;		
		}		
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d %d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1);
		for(int i=1;i<=n;i++)
		{
			if(articulate[i])
			printf("%d is articulate point \n",i);
		}
		printf("Done\n");
		scanf("%d",&n);
	}

}
