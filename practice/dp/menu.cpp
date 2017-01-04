//10:22
#include<bits/stdc++.h>
using namespace std;
typedef double db;
struct retu
{
	db ben;
	int left;
};

int cost[101],ben[101];

retu mem[3][51][101][23];
int next[3][51][101][23];
int n,k,m;
bool f;
retu dp(int same,int prev, int left,int day)
{
	retu ret;
	
	if(day == 0)
	{	
		f = true;
		ret.ben = 0;
		ret.left = left;
		return ret;
	}
	if(mem[same][prev][left][day].ben != 0)
		return mem[same][prev][left][day];
	
	ret.ben = -1000000000;
	ret.left = -1000000000;
	retu temp;
	for(int i=1;i<=n;i++)
	{
		if(prev!= i && cost[i] <=left)
		{
			temp = dp(1,i,left-cost[i],day-1);
			temp.ben += ben[i];
			if(temp.ben > ret.ben)
				ret = temp , next[same][prev][left][day] = i;
			else if(temp.ben == ret.ben && temp.left > ret.left)
				ret = temp , next[same][prev][left][day]  = i;
		}
		else if(prev == i && same == 1 && cost[i] <= left)
		{
			temp = dp(2,i,left-cost[i],day-1);
			temp.ben += (db)ben[i]/2;
			if(temp.ben > ret.ben)
				ret = temp , next[same][prev][left][day]  = i;
			else if(temp.ben == ret.ben && temp.left > ret.left)
				ret = temp , next[same][prev][left][day]  = i;
		}
		else if(prev == i && same == 2 && cost[i] <= left)
		{
			temp = dp(2,i,left-cost[i],day-1);
			if(temp.ben > ret.ben)
				ret = temp , next[same][prev][left][day]  = i;
			else if(temp.ben == ret.ben && temp.left > ret.left)
				ret = temp , next[same][prev][left][day]  = i;
		}
	}
	/*printf("In %d %d %d %d\n",same,prev,left,day);
	printf("Returning ben %lf , left %d\n ",ret.ben,ret.left);*/
	mem[same][prev][left][day] = ret;
	return ret;
}

void dfs(int same,int prev,int left,int day)
{
	if(day == 0)
	{printf("\n");return;}
	int nx = next[same][prev][left][day];
	printf("%d ",nx);	
	
	if(prev == nx && (same == 1 || same == 2))
		dfs(2,nx,left-cost[nx],day-1);
	else if(prev != nx)
		dfs(1,nx,left-cost[nx],day-1);
	
}

int main()
{
	
	scanf("%d %d %d",&k,&n,&m);
	while(n)
	{	
		f = false;
		memset(mem,0,sizeof(mem));
		memset(next,0,sizeof(next));
		for(int i=1;i<=n;i++)
			scanf("%d %d",&cost[i],&ben[i]);
		retu ans = dp(0,0,m,k);
		if(f)
		{
			printf("%0.1lf\n",ans.ben);
			dfs(0,0,m,k);		
		}
		else
		printf("0.0\n");
		scanf("%d %d %d",&k,&n,&m);
	}
}
