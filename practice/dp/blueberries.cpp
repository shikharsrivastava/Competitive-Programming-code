//11:23 25 min
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,n,k,tc;
	scanf("%d",&t);
	tc = 1;
	while(t--)
	{
		scanf("%d %d",&n,&k);
		int berry[n+1];
		for(int i=1;i<=n;i++)
			scanf("%d",&berry[i]);
	
		int dp[n+1][k+1];
		memset(dp,0,sizeof(dp));
		
		for(int lim=1;lim<=k;lim++)
			if(berry[1] <= lim)			
			dp[1][lim] = berry[1];

		for(int bno=2;bno<=n;bno++)
		{
			int val = berry[bno];
			for(int lim = 1;lim<=k;lim++)
			{
				if(val >lim)
					dp[bno][lim] = dp[bno-1][lim];
				else
					dp[bno][lim] = max(dp[bno-2][lim-val]+val,dp[bno-1][lim]);
			}
		}
		printf("Scenario #%d: %d\n",tc,dp[n][k]);
		tc++;
	}
}
