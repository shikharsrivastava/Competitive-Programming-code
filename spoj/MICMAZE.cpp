//9:10

#include<bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>

int main()
{
	int dist,n,m,e,t,u,v,w;
	scanf("%d %d %d %d",&n,&e,&t,&m);
	vector<vector<pii > > g(n+1);
	bool *vis=(bool*)calloc(n+1,sizeof(bool));
	int *d=(int*)calloc(n+1,sizeof(int));
	
	for(int i=0;i<=n;i++)
	d[i]=10000000;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		g[v].push_back(mp(w,u));
	}
	priority_queue<pii > q;
	q.push(mp(0,e));
	d[e]=0;
	while(!q.empty())
	{
		u=q.top().second;
		q.pop();
		if(vis[u])
		continue;
		else
		vis[u]=true;
		for(int i=0;i<g[u].size();i++)
		{
			v=g[u][i].second;
			dist=g[u][i].first;
			if(d[u] + dist < d[v])
			{
				d[v]=d[u]+dist;
				q.push(mp(-d[v],v));
			}
		}
	}
	
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(d[i] <=t)
		ans++;
	}
	printf("%d\n",ans);
}
