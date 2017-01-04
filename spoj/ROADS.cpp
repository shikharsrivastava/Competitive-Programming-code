//21:22

#include<bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>

int main()
{
	int t,n,k,r,s,d,l,tx,dist,tax,u,v;
	int dst[101][10001];
	bool vis[101][10001],flag;
	vector< vector< pair<int, pii > > > g(101);
	scanf("%d",&t);
	priority_queue<pair<int , pii > > q;
	while(t--)
	{

		flag=true;
		scanf("%d %d %d",&k,&n,&r);
		for(int i=0;i<=n;i++)
		g[i].clear();

		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=k;j++)
			{
			dst[i][j]=1000000000;
			vis[i][j]=false;
			dst[1][j]=0;
			}
		}
		for(int i=0;i<r;i++)
		{
			scanf("%d %d %d %d",&s,&d,&l,&tx);
			g[s].push_back(mp(d,mp(l,tx)));
		}	

		q.push(mp(0,mp(0,1)));
		while(!q.empty())
		{
			
			u=q.top().second.second;
			tx=q.top().second.first;
		
			if(u==n && tx<=k)
			{
				flag=false;
				printf("%d\n",-q.top().first);
				break;
			}
			q.pop();

			if(vis[u][tx])
			continue;
			vis[u][tx]=true;
			
			

			for(int i=0;i<g[u].size();i++)
			{
			v=g[u][i].first;
			dist=g[u][i].second.first;
			tax=g[u][i].second.second;
			
			if(tx + tax <= k)
			{
				if(dst[u][tx] + dist < dst[v][tx+tax])
				{
					dst[v][tx+tax]=dst[u][tx]+dist;
					q.push(mp(-dst[v][tx+tax],mp(tx+tax,v)));
				}			
			}

			}
		}
		while(!q.empty())
		q.pop();
		if(flag)
		printf("-1\n");

	}
}
