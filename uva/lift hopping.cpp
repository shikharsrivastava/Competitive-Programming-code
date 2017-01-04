//12:30
#include<bits/stdc++.h>
using namespace std;

#define ppi pair<int , pair<int,int> >
#define mp(a,b)make_pair(a,b)
#define mpp(a,b,c) mp(a,mp(b,c))
bool flag;
int scanint()
{
	flag = false;
	int num = 0;
	char c = getchar_unlocked();
	while(c >= '0' && c <= '9')
	{
		num = num *10 + c - '0';
		c=getchar_unlocked();
	}	
	if(c == '\n')
	flag = true;
	return num;
}
int main()
{
	int n,t,k,time[6],dist[6][101],d,floor,lift,tol,tof,w,u,v;
	vector<vector< pair<int,int>  > > g(101);
	priority_queue<pair< int ,pair<int,int> > > q;
	bool fl;
	t=scanint();
	while(t--)
	{
		fl = false;
		n = scanint();
		k = scanint();
		for(int i=0;i<=100;i++)
		{
			g[i].clear();
			for(int j=0;j<6;j++)
			dist[j][i] = 1000000000;		
		}
		
		for(int i = 1 ; i <= n ; i++)
		time[i]=scanint();
		
		for(int i=1;i<=n;i++)
		{
			u=scanint();
			while(!flag)
			{
				v=scanint();
				g[u].push_back(mp(i,v));
				u=v;
			}
		}

		/*printf("Graph\n");
		for(int i=0;i<100;i++)
		{
			if(g[i].size() >0)
			{
				for(int j=0;j<g[i].size();j++)
				printf(" %d -> %d using lift %d\n",i,g[i][j].second,g[i][j].first);
			}
		}*/
	
		for(int i=0;i<g[0].size();i++)
		{
			q.push(mpp(0,(g[0][i].first),0));
			dist[g[0][i].first][0] = 0;		
		}
		while(!q.empty())
		{
			d = -q.top().first;
			lift = q.top().second.first;
			floor = q.top().second.second;
			
			q.pop();
			if(d > dist[lift][floor])
			continue;
			
			printf("d = %d , lift = %d , floor = %d\n",d,lift,floor);

			if( floor == k )
			{
				printf("%d\n",d);
				fl = true;
				break;
			}
			//printf("Here\n");
			for(int i=0;i<g[floor].size();i++)
			{	
				tof = g[floor][i].second;
				//printf("Inside\n");
				tol = g[floor][i].first;
				//printf("tof = %d , tol = %d , w = %d\n",tof,tol,w);
				w = time[tol] * abs(floor - tof);
				
				if(tol != lift)
				w+=60;
				if(dist[lift][floor] + w < dist[tol][tof])
				{
					dist[tol][tof] = dist[lift][floor] + w;
					q.push(mpp(-dist[tol][tof],tol,tof));
				}				
			}
		}
		if(fl == false)
		printf("IMPOSSIBLE\n");
		else
		{
			while(!q.empty())
			q.pop();
		}
	}
}

