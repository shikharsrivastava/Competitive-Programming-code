//19:15
/*
Modified travelling salesman problem
*/
#include<bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
int n;
map <int,pair<int,int > > m;
int dist[17][1<<8][1<<8];

int dp(int x,int y,int bitc,int bitt,int tp,int id)
{
	int ans=100000000;
	int tox,toy,val;
	if(bitc == (1<<(n))-1)
	{

		dist[id][bitc][bitt] = x+y;
		return x+y;
	}
	
		if(tp < 2)
	{
		// picking up another tool
		for(int i=0;i<n;i++)
		{
			if((bitt >> i) & 1)	//we already have the tool
			continue;
			tox=m[i+n].first;
			toy=m[i+n].second;
			
			if(dist[i+n][bitc][bitt|(1<<i)] >0)
			val = dist[i+n][bitc][bitt|(1<<i)];	
			else
			val = dp(tox,toy,bitc,bitt|(1<<i),tp+1,i+n);	

			ans=min(ans,val+(int)(abs(x-tox)+abs(y-toy)));

		
		}
	}
	
		if(tp > 0)
	{
		// serving the chef
		for(int i=0;i<n;i++)
		{
			if(((bitt>>i) & 1) && ((bitc >>i) & 1) ==0 )	//we have the tool and chef is not served yet
			{
				tox=m[i].first;
				toy=m[i].second;
				if(dist[i][bitc|(1<<i)][bitt] >0)
				val =dist[i][bitc|(1<<i)][bitt];
				else
				val = dp(tox,toy,bitc|(1<<i),bitt,tp-1,i);

				ans = min(ans,val+(int)(abs(x-tox)+abs(y-toy)));			
				
			}
		}
	}
	dist[id][bitc][bitt] = ans;
	return ans;	
}

int main()
{
	int t,x,y,tox,toy,ans,bitt,bitc;
	scanf("%d",&t);
	while(t--)
	{
		m.clear();
		scanf("%d",&n);
		for(int i=0;i<2*n;i++)
		{
			for(int j=0;j<(1<<8);j++)
			{	
				for(int k=0;k<(1<<8);k++)
					dist[i][j][k] = 0;
			}
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&x,&y);
			m[i] = mp(x,y);
			scanf("%d %d",&x,&y);
			m[i+n] = mp(x,y); 
		}
		ans=10000000,bitc=0,bitt=0;
		for(int i=0;i<n;i++)
		{
			tox = m[i+n].first;
			toy = m[i+n].second;

			ans=min(ans,dp(tox,toy,bitc,bitt|(1<<i),1,i+n)+tox+toy);

		}
		printf("%d\n",ans);
	}
}

