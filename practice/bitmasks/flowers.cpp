//3:!6
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
	int n,a,b,k;
	scanf("%d %d",&n,&k);
	lli dp[100005];

	for(int i=1;i<k;i++)
	dp[i] = 1;
	dp[0] = 1; 	
	for(int i=k;i<=n;i++)
	dp[i] = dp[i-k] + dp[i-1];
	while(n--)
	{
		scanf("%d %d",&a,&b);
		printf("%lld\n",dp[b-a+1]);
	}
	
}
