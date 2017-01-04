#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define mp make_pair()
#define pb push_back
#define gym 0
#define code 1

int main()
{
	int n;
	scanf("%d",&n);
	int a[n+1];
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);

	int dp[2][n+10];
	for(int i=1;i<n+10;i++)
	dp[code][i] = dp[gym][i] = 0;
	
	for(int i=n;i>0;i--)
	{
		if(a[i] == 3)
		{
			dp[gym][i] = max(max(dp[gym][i+2]+1,dp[code][i+1]+1),dp[gym][i+1]);
			dp[code][i] = max(max(dp[code][i+2]+1,dp[gym][i+1]+1),dp[code][i+1]);
		}
		else if(a[i] == 1)
		{
			dp[code][i] = max(max(dp[code][i+2]+1,dp[gym][i+1]+1),dp[code][i+1]);
			dp[gym][i] = dp[gym][i+1];
		}
		else if(a[i] == 2)
		{
			dp[gym][i] = max(dp[gym][i+2],dp[code][i+1]) +1;
			dp[code][i] = dp[code][i+1];
		}
		else
		{
			dp[gym][i] = dp[gym][i+1];
			dp[code][i] = dp[code][i+1];
		}
	}
	
	printf("%d\n",n-max(dp[code][1],dp[gym][1]));	
}
