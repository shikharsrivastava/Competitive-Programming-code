//17:11
// include is the boolean array telling us to include the node i in the set of answers
// after all dfs we get ans = number of elements in set , and ans Choose 2 gives us all pairs
#include<bits/stdc++.h>
using namespace std;
vector< vector <int> > g(10001);
int ans,timer,in[10001];
bool vis[10001],fup[10001];
void dfs(int id,int p)
{
	if(vis[id])
	return;
	vis[id] = true;	
	in[id] = ++timer;
	fup[id] = true;
		
	for(int i=0;i<g[id].size();i++)
	dfs(g[id][i],id);
	
	for(int i=0;i<g[id].size();i++)
	{
		if(g[id][i] != p && (in[g[id][i]] <= in[id] || fup[g[id][i]] == false))
		{
			in[id] = min(in[id],in[g[id][i]]);
			fup[id] = false;
		}	
	}
	if( p == 0 && g[id].size() == 0)
	fup[id] = false;	
	if(fup[id])
	ans++;
}

int main()
{
	int t,n,m,u,v;
	scanf("%d",&t);
	while(t--)		
	{
		timer=0,ans =0;
		scanf("%d %d",&n,&m);
		for(int i=0;i<=n;i++)
		{
			g[i].clear();
			vis[i] = false;	
			in[i] = 0;	
		}
		
		for(int i=0;i<m;i++)
		{
			scanf("%d %d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			dfs(i,0);
		}
		printf("%d\n",((long long int)(ans)*(ans-1))/2);
	}
}
