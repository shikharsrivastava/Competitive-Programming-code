//18:45
#include<bits/stdc++.h>
using namespace std;

bool visited[101];
vector<vector< int > > g(101);
void dfs(int id)
{
	if(visited[id])
	return;
	
	visited[id] = true;
	for(int i=0;i<g[id].size();i++)
	dfs(g[id][i]);
}
int  main()
{
	
	int n,x,y;
	scanf("%d",&n);
	int * hashx=(int*)calloc(n+1,sizeof(int));
	int *hashy=(int*)calloc(n+1,sizeof(int));
	

	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&x,&y);
		if(hashx[x] == 0)
		hashx[x] = i;
		else
		{
			g[hashx[x]].push_back(i);
			g[i].push_back(hashx[x]);
		}
		if(hashy[y] == 0)
		hashy[y] = i;
		else
		{
			g[hashy[y]].push_back(i);
			g[i].push_back(hashy[y]);
		}

	}
	int ans=0;
	dfs(1);
	for(int i=1;i<=n;i++)
	{
		if(visited[i])
		continue;
		ans++;
		dfs(i);
	} 
	printf("%d\n",ans);
	free(hashy);
	free(hashx);
}
