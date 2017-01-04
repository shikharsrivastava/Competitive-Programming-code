//20:29
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define mpp(a,b,c,d) mp(mp(a,b),mp(c,d))
#define isValid(y,x,st) ((y >= 0) && (y < r) && (x >=0) && (x < c) && (s[st][y][x] == '.' || s[st][y][x] == 'S' || s[st][y][x] == 'G'))
int incx[4] = { 0 , 1 , 0 , -1};
int incy[4] = { -1, 0 , 1 ,  0 };
char las[4] = {'^' , '>' , 'v' , '<'};
char s[5][101][101];
int main()
{
	int tc,x,y,dist,state,toy,tox,tos,ind,r,c;
	scanf("%d",&tc);
	int dis[4][101][101];
	bool vis[4][101][101],flag;
	priority_queue<pair<pii , pii > > q;
	for(int cas = 1 ;cas <=tc;cas++)
	{
		memset(vis,false,sizeof(vis));
		memset(s,0,sizeof(s));
		flag = false;
		scanf("%d %d",&r,&c);
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<r;j++)
			{
				for(int k =0 ; k<c ;k++)
					dis[i][j][k] = 1000000000;
			}
		}
		for(int i=0;i<r;i++)
			scanf("%s",s[4][i]);
		
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(s[4][i][j] == '^')
				ind = 0;
				else if(s[4][i][j] == '>')
				ind = 1;
				else if(s[4][i][j] == 'v')
				ind = 2;
				else if(s[4][i][j] == '<')
				ind = 3;
				else
				{
					ind = 5;
					for(int k=0;k<4;k++)
					{
						if(s[k][i][j] != '#')
						s[k][i][j] = s[4][i][j];
					}				
				}
				
				for(int st=0;st<4 && ind <4;st++)
					{
						s[st][i][j] = las[ind];
						toy = i+incy[ind] ,tox = j+incx[ind];
						while(isValid(toy,tox,4))
						{
							s[st][toy][tox] = '#';
							toy+=incy[ind];
							tox+=incx[ind];
						}
						ind=(ind+1)%4;
					  }					
				
				if(s[4][i][j] == 'S')
				y=i,x=j;
			}
		}


		dis[0][y][x]=0;

		q.push(mpp(0,0,y,x));
		while(! q.empty())
		{
			y=q.top().second.first;
			x=q.top().second.second;
			dist=-q.top().first.first;
			state=q.top().first.second;
		
			q.pop();
			if(vis[state][y][x])
			continue;
			vis[state][y][x] = true;
			//printf("on y = %d , x = %d , state = %d\n",y,x,state);
	
			if(s[state][y][x] == 'G')
			{
				flag = true;
				printf("Case #%d: %d\n",cas,dist);
				break;
			}
		
			for(int i=0;i<4;i++)
			{
				toy = y + incy[i];
				tox = x + incx[i];
				tos = (state + 1) %4;
				if(isValid(toy,tox,tos))
				{
					if(dis[state][y][x] + 1 < dis[tos][toy][tox])
					{
						dis[tos][toy][tox] = dis[state][y][x] + 1;
						q.push(mpp(-dis[tos][toy][tox],tos,toy,tox));
					}
				}
			}
		}
		if(!flag)
		printf("Case #%d: impossible\n",cas);
		while(!q.empty())
		q.pop();

	}
}
