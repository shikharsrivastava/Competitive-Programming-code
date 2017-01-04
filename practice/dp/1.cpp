//dividing coins 11:05
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int m;
	scanf("%d",&m);
	bool dp[m+1][5001];
	
	int coins[m+1];
	for(int i=1;i<=m;i++)
		scanf("%d",&coins[i]);
	
	sort(coins+1,coins+n+1);

	memset(dp,false,sizeof(dp));

	dp[0][0] = true;
	for(int i=1;i<=m;i++)
	{
		int val = coins[i];
		for(int gap = 0;gap<=5001;gap++)
		{
			if(dp[i-1][gap])
				dp[i][gap+val] = true,
				dp[i][abs(gap-val)] = true;
		}
	}
	for(int gap = 0;gap<=5001;gap++)
		if(dp[m][gap])
		{printf("%d\n",gap);break;}
}
