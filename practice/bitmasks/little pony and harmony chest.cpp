#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
int back[101][1<<17],number[101][1<<17];
int main()
{
	int n;
	scanf("%d",&n);
	int a[n+1],fact[61];
	memset(fact,0,sizeof(fact));
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int primes[17] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
	for(int i=1;i<=60;i++)
		for(int j=0;j<17 && primes[j]<=i;j++)
			if(i%primes[j] == 0)
				fact[i] |= (1<<j);
		
		
	int dp[n+1][1<<17];

	for(int i=1;i<=n;i++)
		for(int j=0;j<1<<17;j++)
			dp[i][j] = 1000000000 , dp[0][j] = 0;

	for(int i=1;i<=n;i++)
		for(int num=1;num<=60;num++)
		{
			int x = (~fact[num]) & ((1<<17)-1);
			for(int s=x;;s=(s-1)&x)
			{
				if(dp[i-1][s] + abs(a[i]-num) < dp[i][s|fact[num]])
					{
						dp[i][s|fact[num]] = dp[i-1][s] + abs(a[i]-num);
						back[i][s|fact[num]] = s;
						number[i][s|fact[num]] = num;
					} 
				if(s==0)
					break; //  written at last to include condition when we take set of all 1's			
			}			
		}

	vector<int> fans;
	int minpos,ans = 1000000000;
	for(int i=0;i<1<<17;i++)
	{
		if(dp[n][i] < ans)
			ans = dp[n][i] , minpos = i;
	}

	for(int i=n;i>=1;i--)
	{
		fans.pb(number[i][minpos]);
		minpos = back[i][minpos];
	}
	for(int i=fans.size()-1;i>=0;i--)
		printf("%d%c",fans[i],i==0?'\n':' ');
}

