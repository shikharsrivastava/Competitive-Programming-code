//10:09
#include<bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define mpp(a,b,c,d) mp(mp(a,b),mp(c,d))
#define isValid(y,x) (y >=0 && y <r && x >=0 && x< c && s[y][x] != '*')
int incx[4] = { 0  , 1 , 0 , -1};
int incy[4] = { -1 , 0 , 1 , 0 };
int dir[4] =  { 0 ,  1 , 2 ,  3};
// 		up ,rgt,dwn,lft
// increment array syncronized according to directions 
int todirec[4][3] = {{0,1,3},{1,0,2},{2,3,1},{3,0,2}}; // if laser is pointing in a direction i , it can go in all directions todirecp[i]
int main()
{
	int r,c,y,x,m,currdir,newdir,tox,toy,w,sx,sy,dir;
	bool flag=false;
	scanf("%d %d",&c,&r);
	char s[r+1][c+1];
	int mir[4][r+1][c+1];
	for(int i=0;i<r;i++)
	{
		scanf("%s",s[i]);
		for(int j=0;j<c;j++)
		{
			for(int k=0;k<4;k++)
			mir[k][i][j] = 100000000;
			if(s[i][j] == 'C')
			sy=i,sx=j;
		}	
	}

	priority_queue<pair<pair<int,int> , pair<int,int> > > q;
	for(int i=0;i<4;i++)
	{
		q.push(mpp(0,i,sy,sx));
		mir[i][sy][sx] = 0;
	}

	while(!q.empty())
	{
		y=q.top().second.first;
		x=q.top().second.second;
		m=-q.top().first.first;
		currdir=q.top().first.second;
		q.pop();
		
		if(m > mir[currdir][y][x])
		continue;
		//printf("On y = %d , x = %d , m = %d , dir = %s\n",y,x,m,direc[d]);		
	
		if(s[y][x] == 'C' && !(y == sy && x == sx))
		{
			flag =true;
			printf("%d\n",m);
			break;
		}
		
		for(int i=0;i<3;i++)
		{
			newdir = todirec[currdir][i];
			tox = x +incx[newdir];
			toy = y +incy[newdir];
			w=1;
			if(isValid(toy,tox))
			{
				if( currdir == newdir )
					w=0;				
				
				if(mir[currdir][y][x] +w < mir[newdir][toy][tox])
				{
					mir[newdir][toy][tox] = mir[currdir][y][x] + w;
					//printf("Pushing toy = %d ,tox = %d , mir = %d ,dir = %s\n",toy,tox,mir[todirec[d][i]][toy][tox],direc[todirec[d][i]]);
					q.push(mpp(-mir[newdir][toy][tox],newdir,toy,tox)); 
				}
				
			}
		}
		
	}
	
}
