//19:12
//19:30
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k,m,u,v,*key;
	bool *vis,*lock,flag;
	vector<vector<int > > g(100001);
	scanf("%d %d %d",&n,&k,&m);
	while(n+k+m > -3)
	{
		vis=(bool *)calloc(n+1,sizeof(bool));
		lock=(bool*)calloc(n+1,sizeof(bool));
		key=(int *)calloc(n+1,sizeof(int));
		flag =false;

		for(int i=0;i<=n;i++)
		g[i].clear();

		for(int i=0;i<k;i++)
		{
			scanf("%d %d",&u,&v);
			key[u] = v;
			lock[v] = true;
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d %d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}

		queue<int> q;
		q.push(1);
		while(!q.empty())
		{
			u=q.front();
			q.pop();
			if(u == n)
			{
				flag = true;
				printf("Y\n");
				break;
			}
			if(vis[u] == true)
			continue;
			vis[u] = true;
		
			if(lock[u])
			continue;
			if(key[u])
			{
				lock[key[u]]= false;
				if(vis[key[u]])
				{
					vis[key[u]]=false;
					q.push(key[u]);			
				}
			}
			for(int i=0;i<g[u].size();i++)
			q.push(g[u][i]);
		}
		if(!flag)
		printf("N\n");
		else
		{
		while(!q.empty())
		q.pop();
		}
		free(vis);
		free(lock);
		free(key);
		scanf("%d %d %d",&n,&k,&m);
	}
	return 0;
}
