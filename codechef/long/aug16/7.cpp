#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
vector<vector<int> > g(10005);
bool inf[10004];
bool vacc[10004];
int depth[10004];
int arr[10004];
int w[10004];
int dist[10004];
int prop[10004];
int s;
int eval(int node)
{
	return 100*w[node] + 20*prop[node] -100*dist[node];
}
bool so(const int a,const int b)
{
	return eval(a) > eval(b);
}
int main()
{
	int n,m,k,u,v;
	scanf("%d %d %d %d",&n,&m,&k,&s);
	
	for(int i=1;i<=n;i++)
	{scanf("%d",&w[i]);arr[i] = i;}
	
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);	
		g[u].pb(v);
		g[v].pb(u);
	}
	inf[s] = true;
	
	queue<int>q;
	q.push(s);
	dist[s] = 1;
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		
		for(int i=0;i<g[node].size();i++)
		if(dist[g[node][i]] == 0)
		prop[node]+= w[g[node][i]],dist[g[node][i]] = dist[node]+1 , q.push(g[node][i]);
	}
	
	sort(arr+1,arr+n+1,so);
	queue<int> bfsq;
	bfsq.push(s);
	depth[s] = 1;
	int when = 1;
	int saved = 0;
	int ptr = 1;
	while(!bfsq.empty())
	{
		int node = bfsq.front();
		bfsq.pop();
		int mx = 0;
		if(depth[node] == when)
		{
			when++;
			while(ptr < n)
			{
				int ind = arr[ptr++];
				if(inf[ind])
				continue;
				else
				{
					printf("%d ",ind);
					saved++;
					vacc[ind] = true;
					break;
				}
			}
			if(ptr >n || saved == k)
			break;
		}
		if(vacc[node])
			continue;
		for(int i=0;i<g[node].size();i++)
			if(!vacc[g[node][i]] && depth[g[node][i]] == 0)
				inf[g[node][i]] = true , depth[g[node][i]] = depth[node]+1 , bfsq.push(g[node][i]);
			
	}
	
	for(int i=saved;i<k;i++)
	printf("%d ",s);
	printf("\n");

	
	
}
