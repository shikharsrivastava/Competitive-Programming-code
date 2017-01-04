//17 :29
#include<bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
#define isValid(x,y) (x>=0 && x<w  && y>=0 && y<h)
using namespace std;
int dist[20][20][20][20];
map<int , pair<int,int> > pos;
char mp[21][21];
int incx[4] = {1,0,-1,0};
int incy[4] = {0,1,0,-1};
int w,h,c;
int hash[20][20][1<<10+3];
// bit is the bitmask storing dirt information , 0 at ith bit  means ith dirt is clean and vice versa
// dp takes , the y , x of current position of robot and the bit i.e dirt information
// it checks through all 2^c combinations of n bit number bit and uses dp using memoisation
// we use dfs to find all pair shortest path in dist for easy calculations
// map pos[i] stores the x and y coordinates of the ith dirt in a pair 
int dp(int y,int x,int bit)
{
	
	if(hash[y][x][bit] >0)
	{
		//printf("At y = %d x = %d , bit = %d ans = %d\n",y,x,bit,hash[y][x][bit]);
		return hash[y][x][bit];
	}		
	int ans=100000000,toy,tox;
	for(int i=0;i<c ;i++)
	{
		toy=pos[i].first;
		tox=pos[i].second;
		if((bit >> i) & 1)
		ans=min(ans,dp(toy,tox,(bit ^ (1<<i))) + dist[y][x][toy][tox]);
	}
	if(ans == 100000000)
	ans=0;
	hash[y][x][bit]=ans;
	//printf("At y = %d x = %d , bit = %d ans = %d\n",y,x,bit,hash[y][x][bit]);
	return ans;
	
}

void bfs(int i, int j)
{
	int tox,toy;

	queue<pair<int,int> > q;
	q.push(mp(i,j));
	dist[i][j][i][j]=0;
	while(! q.empty())
	{
		int y=q.front().first;
		int x=q.front().second;
		
		q.pop();

		for(int k=0;k<4;k++)
		{
			tox =(x+incx[k]);
			toy=(y+incy[k]);
			if(isValid(tox,toy) && dist[i][j][toy][tox] == -1 &&  mp[toy][tox] != 'x')
			{
				dist[i][j][toy][tox] = dist[i][j][y][x]+1;
				q.push(mp(toy,tox));
			}
		}
	}
	
}
int main()
{

	bool flag;

	int sx,sy;
	scanf("%d %d",&w,&h);
	while(w+h >0)
	{
		memset(dist,-1,sizeof(dist));
		pos.clear();
		memset(hash,0,sizeof(hash));
		flag =false;
		for(int i=0;i<h;i++)
		scanf("%s",mp[i]);
		c=0;
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				if(mp[i][j] == '*' || mp[i][j] == 'o')
				{
					if(mp[i][j] == '*')
					pos[c++]=make_pair(i,j);
					if(mp[i][j] == 'o')
					sy=i,sx=j;
					bfs(i,j);
				}
			}
		}

		for(int i=0;i<c;i++)
		{
			if(dist[sy][sx][pos[i].first][pos[i].second] == -1)
			{
				printf("-1\n");
				flag=true;
				break;
			}
		}
		if(!flag)
		{
			int ans=1000000000;
			int bit=0;
			for(int i=0;i<c;i++)
				bit |= (1 << i);
		
			for(int i=0;i<c;i++)
			ans=min(ans,dp(pos[i].first,pos[i].second,bit^(1<<i))+dist[sy][sx][pos[i].first][pos[i].second]);
			printf("%d\n",ans);
		}
	scanf("%d %d",&w,&h);
	}
}
