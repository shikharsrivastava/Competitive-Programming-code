//12:07

#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>

#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<vector<pair<int,pii > > > g(100001);
	bool vis[10001][2],flag;	
	int d[10001][2];
	priority_queue<pair<int,pii > > q;
	int t,u,v,w,f,dist,n,m,k,s,dest,type;
	scanf("%d",&t);
	while(t--)
	{
		flag = true;
		scanf("%d %d %d %d %d",&n,&m,&k,&s,&dest);
		for(int i=0;i<=n;i++)
		{
			g[i].clear();
			vis[i][0]=false;
			vis[i][1]=false;
			d[i][0]=1000000000;
			d[i][1]=1000000000;
		}

		for(int i=0;i<m;i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			g[u].push_back(mp(0,mp(w,v)));
		}

		for(int i=0;i<k;i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			g[u].push_back(mp(1,mp(w,v)));
			g[v].push_back(mp(1,mp(w,u)));
		}
		
		d[s][0]=0;
		d[s][1]=0;
		q.push(mp(0,mp(0,s)));
	//	printf("Source  = %d , destination = %d\n",s,dest);
		while(!q.empty())
		{
			u=q.top().second.second;
			f=q.top().second.first;
			if(u == dest)
			{
				printf("%d\n",-q.top().first);
				flag = false;
				break;
			}
			q.pop();

			if(vis[u][f])
			continue;
		//	printf("u = %d\n",u);
		
			vis[u][f]=true;

			for(int i=0;i<g[u].size();i++)
			{
				v=g[u][i].second.second;
				dist=g[u][i].second.first;
				type=g[u][i].first;
				if((f == 0))
				{
					if(d[u][f] + dist < d[v][type])
					{
						d[v][type]=d[u][f]+dist;
						q.push(mp(-d[v][type],mp(type,v)));
					}
				}
				else if(f == 1 && type == 0)
				{
					if(d[u][f] + dist < d[v][1])
					{
						d[v][1]=d[u][f]+dist;
						q.push(mp(-d[v][1],mp(1,v)));
					}
				}
			}
		}
		if(flag)
		printf("-1\n");
		else
		{
			while(!q.empty())
			q.pop();
		}
		
	}
}

