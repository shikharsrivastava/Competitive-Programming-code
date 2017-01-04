#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
vector<pii> beeper;
#define fi first
#define se second
#define INF 1000000000
int sx,sy;
int dist[10][1<<10];
int findans(int index,int mask)
{
	
	if(dist[index][mask] != 0)
		return dist[index][mask]; 
	int ans = INF;	
	for(int i=0;i<beeper.size();i++)
	{
		if(!((mask>>i)&1))
		{
			int x = beeper[i].fi;
			int y = beeper[i].se;
			ans = min(ans,(abs(x-beeper[index].fi) + abs(y-beeper[index].se))+findans(i,mask | (1<<i)));
		}
	}
	if(ans == INF)
		dist[index][mask] =  abs(sx-beeper[index].fi)+abs(sy-beeper[index].se); 
	else 
		dist[index][mask] = ans;
		return dist[index][mask];
}

int main()
{
	int t,a,b,x,y,m;
	scanf("%d",&t);
	while(t--)
	{
		memset(dist,0,sizeof(dist));
		beeper.clear();
		scanf("%d %d",&a,&b);
		scanf("%d %d",&sx,&sy);
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d %d",&x,&y);	
			beeper.pb(mp(x,y));
		}
				
		int ans = INF;
		for(int i=0;i<beeper.size();i++)
		ans = min(ans,abs(sx-beeper[i].fi) + abs(sy-beeper[i].se) + findans(i,1<<i));
		if(ans == INF)
			printf("The shortest path has length 0\n");
		else
		printf("The shortest path has length %d\n",ans);	
	}
	return 0;
}


