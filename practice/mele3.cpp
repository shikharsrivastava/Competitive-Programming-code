//13:24

#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define mpp(a,b,c) mp(a,mp(b,c))
 
int main()
{
	int k,n,a,b;
	scanf("%d %d",&k,&n);
	vector<vector< pair< bool , pair<int,int > > > > g(k+2);
	int* dist = (int*)calloc((k+1),sizeof(int));
	for(int i=1;i<=k;i++)
	dist[i] = 1000000000;

	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a,&b);
		g[a].push_back(mpp(true,(5*(b-a)),b));
		g[b].push_back(mpp(false,(5*(b-a)),a));
	}
	int ct = 0;
	priority_queue< pii > q;
	dist[1] = 0;
	q.push(mp(0,1));
	while(!q.empty())
	{
		int t = -q.top().first;
		int f = q.top().second;
		q.pop();
		if(t > dist[f])
		continue;
		if(f == k)
		{	
			printf("%d\n",t);
			break;
		}
		
		for(int i=0;i<g[f].size();i++)
		{
			int tof = g[f][i].second.second;
			int travt = g[f][i].second.first;
			bool isStart = g[f][i].first;
			int wt;
			if(isStart)
			{
				if(t % (2*travt) == 0)
				wt = 0;
				else
				wt = 2*travt - (t% (2*travt));
			}
			else
			{
				if(t % (2*travt) <= travt)
				wt = travt - (t % (2*travt));
				else
				wt = travt + 2*travt - (t % (2*travt));	
			}
			if(dist[f] + wt + travt < dist[tof])
			{	
				dist[tof] = dist[f] + wt + travt;
				q.push(mp(-dist[tof],tof));
			}
		}
	}
	
}
