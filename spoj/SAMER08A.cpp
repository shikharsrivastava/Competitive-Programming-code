//11:09 - 11:39
#include<bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
using namespace std;



int main()
{
	int n,m,s,d,u,v,w,dist;
	vector<vector<int> > p(501);
	vector<vector< pii > > g(501);
	bool vis[501],vis2[501];
	int dst[501];
	priority_queue<pii > q;
	queue<int> bq;
	scanf("%d %d",&n,&m);
	while(n+m>0)
	{
		for(int i=0;i<501;i++)
		{
			p[i].clear();
			g[i].clear();
			vis[i]=false;
			vis2[i]=false;
		}
		scanf("%d %d",&s,&d);
		for(int i=0;i<m;i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			g[u].push_back(mp(w,v));
		}
	
		for(int i=0;i<=n;i++)
		dst[i]=1000000000;
		
		dst[s]=0;
		q.push(mp(0,s));
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
				if(dst[u]+dist < dst[v] )
				{
					dst[v]=dst[u]+dist;
					p[v].clear();
					p[v].push_back(u);
					q.push(mp(-dst[v],v));
				} 
				else if(dist + dst[u] == dst[v])
				p[v].push_back(u);
			}
		}
		
		//printf("Shortest path done\n");

		bq.push(d);
		while(!bq.empty())
		{
			u=bq.front();
			bq.pop();
			if(vis2[u])
			continue;
			else
			vis2[u]=true;
			for(int i=0;i<p[u].size();i++)
			{
				v=p[u][i];
				for(int j=0;j<g[v].size();j++)
				{
					if(g[v][j].second == u)
					{
						g[v][j].first=1000000005;
						break;
					}
				}
				bq.push(v);
			}
			
		}
		for(int i=0;i<=n;i++)
		{
			dst[i]=1000000005;
			vis[i]=false;		
		}
		
		dst[s]=0;
		q.push(mp(0,s));
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
				if(dst[u]+dist < dst[v] )
				{
					dst[v]=dst[u]+dist;
					q.push(mp(-dst[v],v));
				} 
			}
		}
		if(dst[d] >= 1000000005)
		printf("-1\n");
		else
		printf("%d\n",dst[d]);
		scanf("%d %d",&n,&m);
	}
}
