//12:06
#include<bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define gotOut(x,y) ( x < minx || x >= maxx || y < miny || y >= maxy ) 
enum {empty,door,wall};
enum {up,down,lft,rgt};
int go[4] = {up , down , lft , rgt};
int incx[4] = { 0 , 0, -1 , 1};
int incy[4] = { 1 , -1 , 0 , 0};
int main()
{
	int n,m,x,y,d,t,dist,maxx,maxy,minx,miny;
	float px,py;
	priority_queue<pair<int,pair<int,int> > > q;
	int g[201][201][4],dis[201][201];
	bool vis[202][202],flag;
	
	scanf("%d %d",&n,&m);
	while( n+m > -2)
	{
		flag =false;
		memset(g,empty,sizeof(g));
		memset(vis,false,sizeof(vis));
		memset(dis,300,sizeof(dis));
		maxx=maxy=-1;
		minx=miny=10000;
		for(int i=0;i<n;i++)
		{
			scanf("%d %d %d %d",&x,&y,&d,&t);
			maxx=max(maxx,x);
			minx=min(minx,x);
			maxy=max(maxy,y);
			miny=min(miny,y);
			if(d==0)
			{	
				maxx=max(maxx,x+t);
				for(int j=0;j<t;j++)
				{
					g[x+j][y-1][up]=wall;
					g[x+j][y][down]=wall;
				}
			}
			else
			{
				maxy=max(maxy,y+t);
				for(int j=0;j<t;j++)
				{
					g[x-1][y+j][rgt]=wall;
					g[x][y+j][lft]=wall;
				}
			}
		}

		for(int i=0;i<m;i++)
		{
			scanf("%d %d %d",&x,&y,&d);
			maxx=max(maxx,x);
			minx=min(minx,x);
			maxy=max(maxy,y);
			miny=min(miny,y);
			if(d==0)
			{
				maxx=max(maxx,x+1);
				g[x][y-1][up]=door;
				g[x][y][down]=door;
			}
			else
			{
				maxy=max(maxy,y+1);
				g[x-1][y][rgt]=door;
				g[x][y][lft]=door;
			}
		}
	
		scanf("%f %f",&px,&py);
		q.push(mp(0,mp((int)px,(int)py)));
		/*printf("minx = %d maxx = %d\n",minx,maxx);
		printf("miny = %d maxy = %d\n",miny,maxy);*/
		while(!q.empty())
		{
			x=q.top().second.first;
			y=q.top().second.second;
			dist=-q.top().first;
			q.pop();
			if(vis[x][y])
			continue;
			vis[x][y]=true;
		
			//printf("On %d %d \n",x,y);
		
			if(gotOut(x,y))
			{
				flag=true;
				printf("%d\n",dist);
				break;	
			}

			for(int i=0;i<4;i++)
			{	
				int tox = x+incx[i];
				int toy = y+incy[i];
				/*printf(" tox = %d , toy  = %d\n",tox,toy);
				printf("%d \n",g[x][y][go[i]]);*/
				
				if(g[x][y][go[i]] != wall)
				{
					//printf("dist  = %d  , d[%d][%d] = %d\n",dist,tox,toy,dis[tox][toy]);
					if(dist + g[x][y][go[i]] < dis[tox][toy])
					{
						
						dis[tox][toy] = dist + g[x][y][go[i]];
						q.push(mp(-dis[tox][toy],mp(tox,toy)));
					}
				}
			}
		}
		while(!q.empty())
		q.pop();

		if(!flag)
		printf("-1\n");

	scanf("%d %d",&n,&m);	
	}
}
