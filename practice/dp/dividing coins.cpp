//dividing coins 11:05
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m;
		scanf("%d",&m);
		int sm = 0;
	
		int coins[m+1];
		for(int i=1;i<=m;i++)
		{	scanf("%d",&coins[i]); sm+= coins[i];}
	
		bool dp[m+1][sm+1];
		sort(coins+1,coins+m+1);

		memset(dp,false,sizeof(dp));

		dp[0][0] = true;
		for(int i=1;i<=m;i++)
		{
			int val = coins[i];
			for(int gap = 0;gap<=sm;gap++)
			{
				if(dp[i-1][gap])
					dp[i][gap+val] = true,
					dp[i][abs(gap-val)] = true;
			}
		}
		for(int gap = 0;gap<=sm;gap++)
			if(dp[m][gap])
			{printf("%d\n",gap);break;}
	}
}
