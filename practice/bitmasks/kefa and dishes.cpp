// Travelling salesman variant - We have to find maximum while going to exactle m nodes, not all n nodes
// Algorithm - lengthwise dp
//A two-dimensional DP will be used to solve the problem. The first dimention is the mask of already taken dishes, and the second — the number of the last taken dish

#include<bits/stdc++.h>
typedef long long int lli;
int m,n;
using namespace std;
int cost[19],dist[19][19];
lli dp[1<<18][19];

int bc(int n)
{
	int c = 0;
	for(int i=19;i>=0;i--)
		if((n>>i)&1)
			c++;
	return c;
}

int main()
{
	int k,u,v,c;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&cost[i]);
	for(int i=1;i<=k;i++)
		{scanf("%d %d %d",&u,&v,&c);dist[u][v] = c;}

	// DP from base
	for(int i=1;i<=n;i++)
	dp[1<<i-1][i] = cost[i];
	// DP begin
	for(int mask=0;mask<=(1<<n)-1;mask++)
		for(int ln = 1;ln<=n;ln++)
			if(mask>>(ln-1) & 1)
				for(int j=0;j<n;j++)
					if(!((mask>>j)&1))
						dp[mask | (1<<j)][j+1] = max(dp[mask|(1<<j)][j+1],cost[j+1]+dist[ln][j+1]+dp[mask][ln]);
				
		
		lli ans = -1;
		for(int mask=0;mask<(1<<n);mask++)
			if(bc(mask) == m)
				for(int ld = 1;ld<=n;ld++)
					ans = max(ans,dp[mask][ld]);
				
			
		cout<<ans<<endl;
}
