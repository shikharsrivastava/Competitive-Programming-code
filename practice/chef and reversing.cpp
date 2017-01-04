//00:09
#include<bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define mpp(a,b,c) mp(a,mp(b,c))
#define pii pair<int,int>
int main()
{
	int n,m,u,v,w,d;
	scanf("%d %d",&n,&m);
	int dist[n+1];
	for(int i=0;i<=n;i++)
	dist[i] = 1000000000;
	vector< vector< pii > > g(n+1);
	
	for(int i=1;i<=n;i++)
	{	
		scanf("%d %d",&u,&v);
		g[u].push_back(mp(0,v));
		g[v].push_back(mp(1,u));
	}

	priority_queue< pii > q;
	dist[1] = 0;
	q.push(mp(0,1));
	while(!q.empty())
	{
		u=q.top().second;
		d=-q.top().first;
		q.pop();
		if(d > dist[u])
		continue;
		
		if( u  == n)
		{
			printf("%d\n",d);
			break;
		}
	
		for(int i=0;i<g[u].size();i++)
		{
			v=g[u][i].second;
			w=g[u][i].first;
			if(dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				q.push(mp(-dist[v],v));
			}
		}
	}
}
