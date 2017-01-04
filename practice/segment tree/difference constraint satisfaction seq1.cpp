/*
	Difference constraint satisfacgtion problem
 	c[] is the array of cumulative frequency
	
	C[i] - C[i-1] <= 1 (1<=i<=N)
	C[i-1] - C[i] <= 0 (1<=i<=N)
	C[i-L1] - C[i] <= -A1 (i-L1>=0)
	C[i] - C[i-L1] <= B1 (i-L1>=0)
	C[i] - C[i-L0] <= L0-A0 (i-L0>=0)
	C[i-L0] - C[i] <= B0-L0 (i-L0>=0)

	After getting the values of c[i] (which may be negative) , we add c[0] to every term to get first positive solution
	Remember in diffeerence constraint satisfaction we have multiple solutions of the form 
	S = <x1   , x2   , x3   , x4   ....>
	S = <x1+d , x2+d , x3+d , x4+d ....>  
*/
#include<bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
bool bellman(vector<vector<pii > > &g , int *dist,int n)
{
	int v,w;
	for(int i=1;i<=n;i++)
	{
		for(int u=0;u<=n;u++)
		{
			for(int e=0;e<g[u].size();e++)
			{
				
				v=g[u][e].second;
				w=g[u][e].first;
				dist[v] = min(dist[v] , dist[u] + w);
			}
		}
	}	
	
	for(int u=0;u<=n;u++)
		{
			for(int e=0;e<g[u].size();e++)
			{
				
				v=g[u][e].second;
				w=g[u][e].first;
				if( min(dist[v] , dist[u] + w) < dist[v])
					return false;
				
			}
		}

	return true;
}

int main()
{
	int n,a0,b0,l0,a1,b1,l1,d[1001];
	vector<vector<pii > >  g(1001);
	for(int tc = 1; tc <= 5;tc ++)
	{
		scanf("%d %d %d %d %d %d %d",&n,&a0,&b0,&l0,&a1,&b1,&l1);

		for(int i=0;i<=n;i++)
		{
			d[i] = 1000000000;
			g[i].clear();
		}
	
	
		for(int i=0;i<=n;i++)
		{
			if(i-1 >=0)
			{
				g[i-1].push_back(mp(1,i));
				g[i].push_back(mp(0,i-1));
				d[i] = 0;
				d[i-1] = 0;		
			}
			if(i-l1 >=0)
			{
				g[i].push_back(mp(-a1,i-l1));
				g[i-l1].push_back(mp(b1,i));
				d[i] = 0;
				d[i-l1] = 0;
			}
			if(i-l0 >=0)
			{
				g[i-l0].push_back(mp(l0-a0,i));
				g[i].push_back(mp(b0-l0,i-l0));
				d[i] = 0;
				d[i-l0] = 0;
			}

		}
	
		if(bellman(g,d,n))
		{
			for(int i=1;i<=n;i++)
			printf("%d",(d[i]-d[0])-(d[i-1]-d[0]));
			printf("\n");
		}
		else
		printf("-1\n");	
	}
}
