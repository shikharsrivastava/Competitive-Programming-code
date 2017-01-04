//21 : 54
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int k;
	char a[2001],b[2001];
	scanf("%s %s",a,b);
	scanf("%d",&k);
	
	int dp[strlen(a)+1][strlen(b)+1];
	memset(dp,0,sizeof(dp));
	
	

	int na = strlen(a) ,nb = strlen(b);

	for(int i=1;i<=na;i++)
		dp[i][0] = i*k;
	for(int i=1;i<=nb;i++)
		dp[0][i] = i*k;
	

	
	for(int i=1;i<=na;i++)
		for(int j=1;j<=nb;j++)
				dp[i][j] = min(dp[i-1][j-1] + abs(a[i-1]-b[j-1]) ,min( dp[i][j-1]+k , dp[i-1][j] + k));
	printf("%d\n",dp[na][nb]);
}

