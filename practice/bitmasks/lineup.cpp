//1:28
#include<bits/stdc++.h>
using namespace std;
int n;
int mem[11][1<<11],a[11][11];

int dp(int pos,int mask)
{
	if(mask == 0 || pos >=n)
		return 0;
	if(mem[pos][mask] !=0)
	return mem[pos][mask];

	int ans = -1000000000;
	for(int i=0;i<n;i++)
	{
		if((mask>>i)&1 && a[pos][n-i-1] !=0)
			ans = max(ans,dp(pos+1,(mask ^ (1<<i)))+a[pos][n-i-1]);
	}
	mem[pos][mask] = ans;
	return ans; 
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		n = 11;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
					scanf("%d",&a[i][j]);					
				
		int ans = -1000000000;
		int av = (1<<n)-1;
		memset(mem,0,sizeof(mem));
		for(int i=0;i<n;i++)
		{	
			if(a[0][n-i-1] != 0)
				ans = max(ans,dp(1,(av ^ (1<<i))) + a[0][n-i-1]);
		}
		printf("%d\n",ans);
	}
}
