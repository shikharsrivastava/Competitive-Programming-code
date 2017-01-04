//15:39

#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define INF 1000000000
#define pii pair<int,int>
#define si set< pii >::iterator 

vector<vector<pair<int ,int > > > g(1000);

struct JOB
{
	int id;
	int pp;
	int from;
};

bool sort(const JOB &a , const JOB &b)
{
	if(a.pp == b.pp)
	return a.id < b.id;
	return a.pp > b.pp;
}
int dist[1000][1000];
int n;
void allpairShortestPath()
{
	for(int s=1;s<=n;s++)
	{
		
		for(int i=1;i<=n;i++)
			dist[s][i] = INF;
		priority_queue<pair<int , int > > q;
		q.push(mp(0,s));
		while(!q.empty())
		{
			int d = -q.top().first;
			int u =  q.top().second;
			
			q.pop();
			if(d > dist[s][u])
			continue;
			dist[s][u] = d;
			for(int i=0;i<g[u].size();i++)
			{
				int to = g[u][i].first;
				int c = g[u][i].second;
				if( d + c < dist[s][to])
				{
					dist[s][to] = d + c;
					q.push(mp(-dist[s][to],to));
				}
			}
		}
	}
}

int main()
{
	int m,b,c,co;
	scanf("%d %d %d %d",&n,&m,&b,&c);
	bool vis[1000];
	JOB job[1000];
	int to[1000],val[1000];
	
	for(int u=1;u<=n;u++)
	{
		for(int v=1;v<=n;v++)
		{
			scanf("%d",&co);
			if(u == v)
			continue;
			g[u].pb(mp(v,co));
		}
	}
	
	allpairShortestPath();
	set<pair<int,int> > lst;
	set<pair<int,int> > jobs;	
	
	for(int i=1;i<=n;i++)
	lst.insert(mp(0,i));	
	
	int canspend = c;
	for(int batch = 1;batch <=m;batch++)
	{	
		
		for(int j=1;j<=b;j++)
		{
			scanf("%d %d",&job[j].from ,&job[j].pp);
			jobs.insert(mp(job[j].pp,j));
		}

			
		while(!jobs.empty())
		{
			
			int minval = lst.begin()->first;
			int maxval = jobs.rbegin()->first;
			
			si maxit = jobs.end();
			maxit--;
			int cost = INF;
			int ansmn,ansmx;
			while(maxit->first == maxval)
			{
				int from = job[maxit->second].from;
				for(si it = lst.begin();it != lst.end() && it->first == minval;it++)
					if(dist[from][it->second] <= cost)
						cost = dist[from][it->second] , ansmn = it->second , ansmx = maxit->second;
				if(maxit == jobs.begin())
				break;
				maxit--;
			}
			if(cost > canspend)
			{
				lst.erase(mp(minval,ansmn));
				lst.insert(mp(minval+maxval,ansmn));
				jobs.erase(mp(maxval,ansmx));
			}
			else
			{
				canspend -= cost;
				to[ansmx] = ansmn;
				lst.erase(mp(minval,ansmn));
				jobs.erase(mp(maxval,ansmx));
				lst.insert(mp(minval+maxval,ansmn));
			}
		}
		
		for(int i=1;i<=b;i++)
		printf("%d\n",to[i]);
		
		fflush(stdout);
	}

	
	
}
