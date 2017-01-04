//16:18
// R G B Y
// 1 1 1 1
#include<bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define mpp(a,b,c,d) mp(mp(a,b),mp(c,d))
#define isValid(y,x) ( y >=0 && y< r && x>=0 && x< c)
#define isRed(x) (x>>3 & 1)
#define isGreen(x) (x>>2 & 1)
#define isBlue(x) (x>>1 & 1)
#define isYellow(x) (x & 1)
#define addR(x) (x | (1<<3))
#define addG(x) (x | (1<<2))
#define addB(x) (x | (1<<1))
#define addY(x) (x | (1))
// using bit as our bitmask to represent the keys we are having
// expanding the graph so that each node has (1<<4) 16 states , representing all combinations of the keys
// then using simple bfs from starting position and transitioning to different states on finding a key
// we insert distance , bit (key information) , y , x in queue
// Since bfs travels by level , so all equidistant nodes (in any state) are reached before going to distance +1
// The first time we reach the exit is the shortest route to exit and the bit save the keys we are having
int incx[4]={ 1 , -1 , 0 , 0 };
int incy[4]={ 0 , 0 , 1 , -1 };
int main()
{	
	char s[101][101];
	bool vis[101][101][1<<4],flag;
	
	int dist,bit,r,c,x,y,toy,tox;
	scanf("%d %d",&r,&c);
	while(r+c > 0)
	{
		memset(vis,false,sizeof(vis));
		flag =false;

		for(int i=0;i<r;i++)
		{
			scanf("%s",s[i]);
			for(int j=0;j<c;j++)
			{
				if(s[i][j] == '*')
				y=i,x=j;
			}
		}
		bit = 0;
		queue<pair<pair<int,int> , pair<int,int> > > q;
		q.push(mpp(0,bit,y,x));
		while(!q.empty())
		{
			dist=q.front().first.first;
			bit=q.front().first.second;
			y=q.front().second.first;
			x=q.front().second.second;
		
			q.pop();

			if(vis[y][x][bit])
			continue;
			//printf("On r = %d , c = %d bit = %d dist = %d %c\n",y,x,bit,dist,s[y][x]);
			vis[y][x][bit]=true;
	
			if(s[y][x] == 'X')
			{
				flag = true;
				printf("Escape possible in %d steps.\n",dist);
				break;
			}
			for(int i=0;i<4;i++)
			{
				toy=y+incy[i];
				tox=x+incx[i];
				if(isValid(toy,tox))
				{
					switch(s[toy][tox])
					{
						case 'R': if(isRed(bit))
							  q.push(mpp(dist+1,bit,toy,tox));
							  break;
						case 'G': if(isGreen(bit))
							  q.push(mpp(dist+1,bit,toy,tox));
							  break;
						case 'B': if(isBlue(bit))
							  q.push(mpp(dist+1,bit,toy,tox));
							  break;
						case 'Y': if(isYellow(bit))
							  q.push(mpp(dist+1,bit,toy,tox));
							  break;	
						case 'r': q.push(mpp(dist+1,addR(bit),toy,tox));
							  break;
						case 'g': q.push(mpp(dist+1,addG(bit),toy,tox));
							  break;
						case 'b': q.push(mpp(dist+1,addB(bit),toy,tox));
							  break;
						case 'y': q.push(mpp(dist+1,addY(bit),toy,tox));
							  break;
						case '#':break;
						default: q.push(mpp(dist+1,bit,toy,tox));
					}
				}
			}
		
		}
		while(!q.empty())
		q.pop();
		if(!flag)
		printf("The poor student is trapped!\n");
		scanf("%d %d",&r,&c);	
	}
}
