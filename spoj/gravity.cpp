//21:40
#include<bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define mpp(a,b,c) mp(a,mp(b,c))
#define isValid(x,y) (x>=0 && x< c && y>=0 && y<r && s[y][x] != '#')
int incx[8]={0,0,1,1,1,-1,-1,-1};
int incy[8]={1,-1,0,1,-1,0,1,-1};
int main()
{
	int t,o,r,c,x,y,sx,sy,tox,toy;
	bool flag;
	scanf("%d",&t);
	int d[105][105];
	char s[105][105];
	queue<pair<int, pair<int,int> > > q;
	while(t--)
	{	
		flag =true;
		scanf("%d %d %d",&o,&r,&c);
		for(int i=0;i<=r;i++)
			for(int j=0;j<=c;j++)
				d[i][j] = 0;
		getchar_unlocked();
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c+1;j++)
			{
				s[i][j] = getchar_unlocked();
				if(s[i][j] == 'S')
				sy = i, sx = j;	
			}
		}


		
		q.push(mpp(o,sx,sy));
		while(!q.empty())	
		{
			o=q.front().first;
			x=q.front().second.first;
			y=q.front().second.second;
			q.pop();
			if(d[y][x] >0 || o < 0)
			continue;
			d[y][x]=1;
			if(s[y][x] == 'T')
			{
				flag =false;
				printf("Possible\n");
				break;
			}
					
			for(int i=0;i<8;i++)
			{
			tox = x+incx[i];
			toy = y+incy[i];
			if(isValid(x,y))
			q.push(mpp(o-1,tox,toy));
			} 		
		}	
		if(flag)
		{
			printf("Impossible\n");
			while(!q.empty())
			q.pop();
		}
	}
	return 0;
}
