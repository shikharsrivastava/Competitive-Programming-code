//21:17 wt

#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp(a,b)make_pair(a,b)

vector<vector<pii> > g1(100001),g2(1000001);
int dis1[1000001],dis2[1000001];

void dijkastra(vector<vector<pii > > &g , int *dis ,int s)
{
	int u,v,d;
	priority_queue<pair<int,int> > q;
	q.push(mp(0,s));
	dis[s] = 0;
	while(!q.empty())
	{
		u=q.top().second;
		d=-q.top().first;
		q.pop();
		if(d > dis[u])
		continue;

		for(int i=0;i<g[u].size();i++)
		{	
			v=g[u][i].second;
			d=g[u][i].first;
			if(dis[u] + d < dis[v])
			{
				dis[v] = dis[u] + d;
				q.push(mp(-dis[v],v));
			}
		}
	}
	
}
int main()
{
	int t,n,m,u,v,w;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			g1[i].clear();
			g2[i].clear();
			dis1[i]=100000000;
			dis2[i]=100000000;		
		}
	
		for(int i=0;i<m;i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			g1[u].push_back(mp(w,v));
			g2[v].push_back(mp(w,u));
		}
	
		dijkastra(g1,dis1,1);
				
		dijkastra(g2,dis2,1);
	
		int ans=0;
		for(int i=1;i<=n;i++)
		ans+=dis1[i]+dis2[i];

	printf("%d\n",ans);
		
	}
}
