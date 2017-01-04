//22:50
#include<bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
struct spark
{
	int x,y;
	vector<int> adj;
	vector<float> dist;
	int id;
	bool lit;
	int s;
	float t;
};
int main()
{
	int n,arr,toid,x,y,tox,toy,id;
	float t;
	scanf("%d",&n);
	spark * a=(spark*)calloc(n+1,sizeof(spark));
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].s);
		for(int j=0;j<n-1;j++)
		{
			scanf("%d",&arr);
			a[i].adj.push_back(arr);
		}	
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<a[i].adj.size();j++)
		{
			x = a[i].x;
			y = a[i].y;
			tox = a[a[i].adj[j]].x;
			toy = a[a[i].adj[j]].y;
			a[i].dist.push_back(sqrt(pow((x-tox),2)+pow((y-toy),2)));
		}
	}

	priority_queue<pair<float,int> >q;
	q.push(mp(-0.0,1));
	while(!q.empty())
	{
		t=-q.top().first;
		id=q.top().second;
		q.pop();
		if(a[id].lit)
		continue;
		
		a[id].lit = true;
		a[id].t=t;
		for(int i=0;i<a[id].adj.size();i++)
		{
			toid = a[id].adj[i];
			
				if(a[id].s >0)
				{
					if(!a[toid].lit)
					{
						q.push(mp(-(t+a[id].dist[i]),a[id].adj[i]));
						a[id].s-=1;						
					}
				}
		}
	}
	for(int i=1;i<=n;i++)
	printf("%f\n",a[i].t);
	
}
