//11:53

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef double db;
vector<int > g[100001];
pair< pair<int,int> ,int> e[10001];
bool vis[501][501];
db dist[501];
int n,m,a,b;

bool cango(db k)
{
	for(int i=1;i<=n;i++)
		dist[i] = 1000000000;
	dist[a] = 0	;
	
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int u = e[j].first.first;	
			int v = e[j].first.second;
			db w = e[j].second - k;
			if(dist[u] + w < dist[v])
				dist[v] = dist[u]+w;
		}
	}
	if(dist[b] <= 0)
		return true;
	else
	{
		for(int i=1;i<=m;i++)
		{	
			int u = e[i].first.first;	
			int v = e[i].first.second;
			db w = e[i].second - k;
			if(dist[u] + w < dist[v] && vis[a][u] && vis[v][b])
				return true;
		}
	}
	return false;
}

void dfs(int id,int pa)
{
	vis[pa][id] = true;
	for(int i=0;i<g[id].size();i++)
		if(!vis[pa][g[id][i]])
			dfs(g[id][i],pa);
}
int main() 
{
	int t,u,v,w;
	scanf("%d",&t);
	while(t--)
	{	
		int mx = -1;
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++)
			g[i].clear();
		memset(vis,false,sizeof(vis));
		for(int i=1;i<=m;i++)
		{	
			scanf("%d %d %d",&u,&v,&w);
			g[u].pb(v);
			e[i] = (mp(mp(u,v),w));
			mx = max(mx,w);
		}
		scanf("%d %d",&a,&b);
		for(int i=1;i<=n;i++)
				dfs(i,i);
		
		if(!vis[a][b])
			{printf("-1\n");continue;}
		db s = 0 , e = mx;
		while(e-s > (0.0000001))
		{
			db m = (s+e)/2;
			if(cango(m))
				e = m;
			else
				s = m;
		}
		printf("%lf\n",s);
	}
}

