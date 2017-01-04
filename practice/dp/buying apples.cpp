#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000
int dp[101][101][101];
int main()
{
	int a[101];

	int t,n,k;
	scanf("%d",&t);
	while(t--)
	{	
		scanf("%d %d",&n,&k);
		for(int i=1;i<=k;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<=n;i++)
			for(int j=0;j<=k;j++)
				for(int l=0;l<=k;l++)
					dp[i][j][l] = INF;
			for(int i=0;i<=k;i++)
				dp[0][i][0] = 0;
		
		for(int ind=1;ind<=n;ind++)
		{
			for(int i=1;i<=k;i++)
			{
				for(int w=1;w<=k;w++)
				{
					if(a[i] == -1)
						dp[ind][i][w] = dp[ind][i-1][w];
					else
					{
						if(w>=i)
						dp[ind][i][w] = min(a[i]+dp[ind-1][i][w-i] , dp[ind][i-1][w]);
						else
						dp[ind][i][w] = dp[ind][i-1][w];
					}
				}
			}
		}
		int ans = 1000000007;
		for(int i=1;i<=n;i++)
			ans = min(ans,dp[i][k][k]);
		if(ans >=INF)
			printf("-1\n");
		else
			printf("%d\n",ans);
		
	}
}
