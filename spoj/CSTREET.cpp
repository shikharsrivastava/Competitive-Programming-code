//18:07
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)

int main()
{
	int t,p,n,u,v,m,w,ans,dist;
	vector<vector<pii > > g(1001);
	priority_queue<pii> q;
	bool vis[1001];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&p);
		scanf("%d",&n);
		for(int i=0;i<=n;i++)
		{
			g[i].clear();
			vis[i]=false;
		}

		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			g[u].push_back(mp(w,v));
			g[v].push_back(mp(w,u));
		}
		ans=0;
		q.push(mp(0,u));
		while(!q.empty())
		{
			u=q.top().second;
			dist=-q.top().first;
			q.pop();
			if(vis[u])
			continue;
			vis[u]=true;
			ans+=dist;
			//printf("u = %d , dist = %d\n",u,dist);
			for(int i=0;i<g[u].size();i++)
			{	
				v=g[u][i].second;
				dist=g[u][i].first;
				q.push(mp(-dist,v));
			}
				
		}
		printf("%d\n",ans*p);
	}
}
