// Set Cover Problem - Dynammic programing

#include<bits/stdc++.h>
using namespace std;
int n,l[301],c[301],m[301],dp[301][1<<10];

int findans(int id)
{

	int num = l[id];

	vector<int> fact;
	for(int i=2;i*i <= num;i++)
	{
		if(num % i == 0)
		fact.push_back(i);
		while(num % i ==0)
			num /= i;
	}
	if(num >=2)
		fact.push_back(num);
	int N = fact.size();
	// Using prime factors as bitmasks
	for(int i=0;i<=n;i++)
		{ m[i] = 0;
			for(int mask =0 ;mask <=(1<<N);mask++)
			dp[i][mask] = 1000000000;
		}
		dp[0][0] = 0;
	
	for(int i=1;i<=n;i++)
		for(int f=0;f<N;f++)
			if(l[i] % fact[f] != 0)	// Marking bitmasks position of all nummbers which do not contain factor number i
				m[i] |= (1<<f);

	// Set cover DP
	for(int i=1;i<=n;i++)
		for(int mask = 0;mask<=(1<<N)-1;mask++)
			dp[i][mask] = min(dp[i-1][mask] , c[i] + dp[i-1][mask&(~m[i])]);
	return dp[n][(1<<N)-1];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	
		scanf("%d",l+i);
	for(int i=1;i<=n;i++)
		scanf("%d",c+i);
	
	int ans = 1000000000,anss;
	for(int i=1;i<=n;i++)
			ans = min(ans,c[i] + findans(i));
			
	if(ans == 1000000000)
	ans = -1;
	printf("%d\n",ans);
}
