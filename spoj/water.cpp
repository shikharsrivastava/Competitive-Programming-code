//21:58
#include<bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define mpp(a,b,c) mp(a,mp(b,c))
#define isValid(y,x) (y>=0 && y<n && x>=0 && x<m)
int incx[4] = { 1 , -1 , 0 , 0};
int incy[4] = { 0 , 0 , 1 , -1};
int a[101][101];
bool vis[101][101];
int main()
{
	int t,n,m,ans,toy,tox;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++)
		{	for(int j=0;j<m;j++)
			{	scanf("%d",&a[i][j]);vis[i][j] = false; }
		}
	
		priority_queue< pair<int,pair<int,int > > > pq;
		for(int i=0;i<m;i++)
		{
			pq.push(mpp(-a[0][i],0,i));
			pq.push(mpp(-a[n-1][i],n-1,i));
		}
		for(int i=0;i<n;i++)
		{
			pq.push(mpp(-a[i][0],i,0));
			pq.push(mpp(-a[i][m-1],i,m-1));
		}
		int y,x,h;
		queue<pair<int,int > > q;
		while(!pq.empty())
		{
			h=-pq.top().first; // current height of water upto which all places reacheble from boundary (found using bfs) should be filled 
			y=pq.top().second.first;
			x=pq.top().second.second;
			pq.pop();
			if(vis[y][x])
			continue;

			q.push(mp(y,x));
			while(!q.empty())
			{
				y=q.front().first;
				x=q.front().second;
				q.pop();
				if(vis[y][x])
				continue;
				vis[y][x] = true;
				ans+=h-a[y][x];
				
				for(int i=0;i<4;i++)
				{
					tox=x+incx[i];
					toy=y+incy[i];
					if(isValid(toy,tox))
					{
						if(a[toy][tox] <= h)
						q.push(mp(toy,tox));
						else
						pq.push(mpp(-a[toy][tox],toy,tox));
					}
				}
			}
			vis[y][x]=true;
		
		}
		printf("%d\n",ans);
	}
	return 0;
}
	
