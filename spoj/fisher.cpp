//20:39

#include<bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
using namespace std;
int main()
{
	vector<vector<pii > > gd(501);
	vector<vector<pii > > gt(501);
	
	priority_queue<pair<int, pii > > q;

	bool vis[501][1001];
	int d[501][1001];
	int u,v,t,n,c,cst,dist;
	scanf("%d %d",&n,&t);
	while(n+t >0)
	{

		for(int i=0;i<=n;i++)
		{
		gd[i].clear();
		gt[i].clear();
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&dist);
				gt[i].push_back(mp(dist,j));
			}			
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&dist);
				gd[i].push_back(mp(dist,j));
			}			
		}
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=t;j++)
			{
				vis[i][j]=false;
				d[i][j]=1000000000;
				d[0][j]=0;
			}

		}

		q.push(mp(0,mp(0,0)));
		while(!q.empty())
		{
			u=q.top().second.second;
			c=q.top().second.first;
			
			if(u == n-1 && c <=t)
			{
				printf("%d %d\n",-q.top().first,c);
				break;
			}
			q.pop();
			if(vis[u][c])
			continue;
			vis[u][c]=true;
			
			for(int i=0;i<gd[u].size();i++)
			{
				dist=gd[u][i].first;
				cst=gt[u][i].first;
				v=gd[u][i].second;
				if(c+cst <=t)
				{
					if(d[u][c] + dist < d[v][c+cst])
					{
						d[v][c+cst]=d[u][c]+dist;
						q.push(mp(-d[v][c+cst],mp(c+cst,v)));
					}
				}
			}
		}
		while(!q.empty())
		q.pop();
		scanf("%d %d",&n,&t);
	}

}
