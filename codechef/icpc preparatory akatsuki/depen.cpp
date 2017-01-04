#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> g[100005];
typedef long long ll;
int cnt[100005];
set<int> resolved;
set<int> unresolved;
#define INF 100000000000000000LL
void recurse(int id)
{
	for(int i=0;i<g[id].size();i++)
	{
		int v = g[id][i];
		cnt[v]--;
		if(!cnt[v])
		{
			resolved.insert(v);
			unresolved.erase(v);
			recurse(v);
		}
	}
}
int main()
{
	int n,m,d,u,v;
	scanf("%d %d %d",&n,&m,&d);
	ll dist[n+1];
	ll ans = 0;
	for(int i=1;i<=n;i++)
		scanf("%lld",&dist[i]);
	
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		g[u].pb(v);
		
		if(dist[v] < d)
		{unresolved.insert(v);cnt[v]++;}
	}

	for(int i=1;i<=n;i++)
	{
		//printf("at %d\n",dist[i]);
		if(dist[i] >= d)
		{
			//printf("dist > d\n");
			//printf("Adding %lld\n",2*(d-dist[*unresolved.begin()]));
			ll mindist = INF;
			if(!unresolved.empty())
			mindist = min(mindist,dist[*unresolved.begin()]);
			if(!resolved.empty())
			mindist = min(mindist,dist[*resolved.begin()]);
			if(mindist != INF)
			ans += (ll)2*(d-mindist);
			break;
		}

		if(cnt[i]) continue;
		recurse(i);
		if(unresolved.empty())
		{
			if(!resolved.empty())
			ans += (ll)2*(dist[i] - dist[*resolved.begin()]);
			break;	
		}
	
		if(!resolved.empty() && dist[i] < dist[*unresolved.begin()])
		{
			//printf("can resolve someone\n");	
			//printf("Adding %lld\n",2*(dist[i] - dist[*resolved.begin()]));
			ans += (ll)2*(dist[i] - dist[*resolved.begin()]);
			resolved.clear();
		}
	}
	
	ans += dist[n] + abs(dist[n]-d);
	printf("%lld\n",ans);
}
