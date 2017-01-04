//22:07
#include<bits/stdc++.h>
#define isValid(r,c) (r>0 && r<=n && c>0 && c<=m && ar[tor][toc] == 0)
using namespace std;
int ar[101][101];
#define pii pair<int,int>
#define mp make_pair
#define mpp(a,b,c) mp(a,mp(b,c))
#define INF 1000000000

int incr[4] = {1,-1,0,0};
int incc[4] = {0,0,1,-1};
int dist[3][101][101];
int n,m;
void bfsdist(int id,int sr,int sc,int k)
{
	if(k == 0)
	{dist[id][sr][sc] = 0; return;}
	queue<pair<int,pii > > q;
	int r,c,d,tor,toc;
	q.push(mpp(0,sr,sc));
	dist[id][sr][sc] = 0;
	while(!q.empty())
	{
		d = q.front().first;
		r = q.front().second.first;
		c = q.front().second.second;
		q.pop();
		
		for(int md=1;md<=k;md++)
		{
			for(int dir=0;dir<4;dir++)
			{
				tor = r + md*incr[dir];
				toc = c + md*incc[dir];
				
				if(tor == r)
				{
					for(int todir = 0;todir<2;todir++)
					{
						for(int l=0;l<=k-md;l++)
						{
							tor = r + l*incr[todir];
							if(isValid(tor,toc) && d+1 < dist[id][tor][toc])
							{
								dist[id][tor][toc] = d+1;
								q.push(mpp(d+1,tor,toc));
							}
						}
					}
				}
				else
				{
					for(int todir = 2;todir<4;todir++)
					{
						for(int l=0;l<=k-md;l++)
						{
							toc = c + l*incc[todir];
							if(isValid(tor,toc) && d+1 < dist[id][tor][toc])
							{
								dist[id][tor][toc] = d+1;
								q.push(mpp(d+1,tor,toc));
							}
						}
					}
				}
			}
		}
	}
}


int main()
{
	int t,ans;
	int k[3];
	scanf("%d",&t);
	while(t--)
	{
		ans = INF;
		scanf("%d %d %d %d",&n,&m,&k[1],&k[2]);
		
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				{
					scanf("%d",&ar[i][j]);
					dist[1][i][j] = dist[2][i][j] = INF;
				}

		if(m==1)
		{printf("0\n");continue;}

	bfsdist(1,1,1,k[1]);
	bfsdist(2,1,m,k[2]);	
	
			
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans = min(ans,max(dist[1][i][j],dist[2][i][j]));
	if(ans == INF)
	printf("-1\n");
	else
	printf("%d\n",ans);
	}
	return 0;
}
