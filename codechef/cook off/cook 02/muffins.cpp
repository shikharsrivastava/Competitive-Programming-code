//20:17
#include<bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define mpp(a,b,c) mp(a,mp(b,c))

vector<vector<pair<int,int> > > g(100001);
vector<pair<bool,pair<int,int> > > e;
int m;
bool VertexCover(int k)
{
	int index = -1,u,v,id;
	for(int i=0;i<m;i++)
	{
		if(e[i].first)
		{
			index = i;
			break;
		}
	}
	
	if(index == -1)
		return true;

	if(k == 0)
	return false;

	u = e[index].second.first;
	v = e[index].second.second;
	// taking u in vc
	for(int i=0;i<g[u].size();i++)
	{
		id = g[u][i].first;
		e[id].first = false; 

	}

	bool f = VertexCover(k-1);

	// returning back
	for(int i=0;i<g[u].size();i++)
	{
		
		id=g[u][i].first;
		e[id].first = true;
	}

	// taking v in vc
	for(int i=0;i<g[v].size();i++)
	{
		
		id=g[v][i].first;	
		e[id].first = false;
	}
	bool s = VertexCover(k-1);
	// returning back
	for(int i=0;i<g[v].size();i++)
	{
		id=g[v][i].first;
		e[id].first = true;
	}
	return f|s;
}

int main()
{
	int t,n,gs,u,v;
	scanf("%d",&t);
	while(t--)
	{
		e.clear();
		scanf("%d %d %d",&n,&m,&gs);
		for(int i=0;i<=n;i++)
		g[i].clear();
		int vc=n-gs;
		for(int i=0;i<m;i++)
		{	
			scanf("%d %d",&u,&v);
			g[u].push_back(mp(i,v));
			g[v].push_back(mp(i,u));
			e.push_back(mpp(true,u,v));
		}
		if(VertexCover(vc))
		printf("Possible\n");
		else
		printf("Impossible\n");
	}
}
