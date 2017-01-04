#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define MX 10000000000000
typedef long long int lli;
lli dp[101][101][101];
int color[101][101];
int a[101],m;
lli findans(int s,int e,int p)
{
	printf("S = %d ,e = %d , p = %d\n",s,e,p);
	
	if(e-s+1 < p)
	{return dp[s][e][p];}
	if(dp[s][e][p] != MX)
		{printf("Ans = %lld\n",dp[s][e][p]);return dp[s][e][p];}

	if(p ==1)
	{
		int val = 0;
		for(int i=s;i<=e;i++)
			if(a[i] != 0)
				val = a[i];
		if(val >0)
		{
			lli ans = 0;
			for(int i=s;i<=e;i++)
				if(a[i] == 0)
					ans += color[i][val];
				else if(a[i] != val)
					{dp[s][e][p]= MX+1;/*printf("Ans = %lld\n",dp[s][e][p]);*/return dp[s][e][p];}
			
			dp[s][e][p] = ans;
			//printf("Ans = %lld\n",dp[s][e][p]);
			return dp[s][e][p];	
		}
		else
		{
			//printf("Here\n");
			lli fans = MX;
			for(int c=1;c<=m;c++)
			{
				lli ans = 0;
				for(int i=s;i<=e;i++)
					ans += color[i][c];
				fans = min(fans,ans);
			}
			dp[s][e][p] = fans;
			//printf("Ans = %lld\n",dp[s][e][p]);
			return dp[s][e][p];
		}
	}
	lli ans = MX;
	for(int i=s;i<e;i++)
		ans = min(ans,findans(s,i,1)+findans(i+1,e,p-1));
	//printf("Ans = %lld\n",dp[s][e][p]);
	return ans;
}
int main()
{
	int n,k;
	scanf("%d %d %d",&n,&m,&k);
	
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&color[i][j]);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			for(int l=0;l<=k;l++)
				dp[i][j][l] = MX;
	
	lli ans = findans(1,n,k);
	if(ans <MX)
		cout<<ans<<endl;
	else
		cout<<"-1"<<endl;
}	
