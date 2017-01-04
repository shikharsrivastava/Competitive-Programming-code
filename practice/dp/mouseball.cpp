#include<bits/stdc++.h>
using namespace std;

int main()
{
	int make[] = {2,3,6,7,8};

	long long dp[100001];
	
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	for(int j=0;j<5;j++) 
	for(int i=1;i<=100000;i++)
		if(i-make[j] >=0)
				dp[i] += dp[i-make[j]];
	
	int n,t;
	scanf("%d",&t);
	while(t--)
	{	
		scanf("%d",&n);
		printf("%lld\n",dp[n]);
	}
}
