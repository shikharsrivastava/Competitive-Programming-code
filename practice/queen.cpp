//11:07
#define isValid(y,x) (y>=0 && y< n && x>=0 && x<n && bd[y][x] != 'X')
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define mpp(a,b,c,d) mp(mp(a,b),mp(c,d))
#define adddir(a,d) ( a |= (1<<d))
#define isdir(a,d) (a & (1<<d))
#include<bits/stdc++.h>
using namespace std;
int incx[8] = {0,1,1,1,0,-1,-1,-1}; 
int incy[8] = {-1,-1,0,1,1,1,0,-1};
int todir[8][7] = {{0,1,2,3,5,6,7},{0,1,2,3,4,6,7},{0,1,2,3,4,5,7},{0,1,2,3,4,5,6},{1,2,3,4,5,6,7},{0,2,3,4,5,6,7},{0,1,3,4,5,6,7},{0,1,2,4,5,6,7}};

int dist[1001][1001];
int dir[1001][1001];
char bd[1001][1001];
int main()
{
	int r,c,sc,sr,fc,fr,n,m,t,moves,d;
	bool flag;
	
	priority_queue<pair<pii , pii> > q;
	scanf("%d",&t);
	while(t--)
	{
		flag = true;
		scanf("%d %d",&n,&m);
		for(r = 0 ; r < n ;r++)
		scanf("%s",bd[r]);
		for(r=0;r<n;r++)
		{
			for(c=0;c<m;c++)
			{
				dist[r][c] = 1000000000, dir[r][c] = 0;
				if(bd[r][c] == 'S')
				sr = r , sc = c;
				if(bd[r][c] == 'F')
				fr = r , fc = c; 
			}
		}	
		for(int i=0;i<8;i++)
		{
			dist[sr][sc] = 1;
			q.push(mpp(-1,i,sr,sc)); 
		}

		while(!q.empty())
		{
			moves = -q.top().first.first;
			d = q.top().first.second;
			r = q.top().second.first;
			c = q.top().second.second;
			q.pop();
			if(isdir(dir[r][c],d))
			continue;
			if(moves > dist[r][c])
			continue;
			adddir(dir[r][c],d);
			if(r == fr && c == fc)
			{printf("%d\n",moves);flag = false;break;}
		
			for(int i=0;i<7;i++)
			{
				int todirec = todir[d][i];
				int tor = r + incy[todirec];
				int toc = c + incx[todirec];
				int wt = 0;
				if(!isValid(tor,toc))
				continue;
				if(todirec != d)
				wt = 1;
				if(!isdir(dir[tor][toc],todirec) && (moves + wt <= dist[tor][toc]))
				{
					dist[tor][toc] = moves + wt;
					q.push(mpp(-dist[tor][toc],todirec,tor,toc));
				}
			}
		}
		if(flag)
		printf("-1\n");
		while(!q.empty())
		q.pop();
		
	}
}
