//10:58
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,u,v;
	scanf("%d",&n);
	vector<vector<int > > g(n+1);
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int *vis=(int*)calloc(n+1,sizeof(int));
	int ans=100000,level=0;
	queue<int> q;
	set<int> s;
	for(int i=1;i<=n;i++)
	{
		level=0;
		q.push(i);
		for(set<int>::iterator it =s.begin(); it!=s.end(); it++)
		vis[*it]=0;
		
		while(!q.empty())
		{
			u=q.front();
			q.pop();
			if(level == 2)
			break;
		
			for(int j=0;j<g[u].size();j++)
			{
				int to=g[u][j];
				vis[to]++;
				s.insert(to);
				if(vis[to] == 2)
				{
					ans=min(ans,(int)g[i].size()-2+(int)g[u].size()-2+(int)g[to].size()-2);
					vis[to]--;
				}
				q.push(to);
			}
			level++;
		}
		while(!q.empty())
		q.pop();
	}
	if(ans == 100000)
	printf("-1\n");
	else
	printf("%d\n",ans);
}
