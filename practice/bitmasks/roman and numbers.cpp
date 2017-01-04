//10:31
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pb push_back
lli dp[1<<19][100];
vector<int>dig;
lli n,m;
lli findans()
{
	int n = dig.size();
	for(int i=0;i<n;i++)
		if(dig[i])
			dp[1<<i][dig[i]%m] = 1;

	for(int i=0;i<1<<n;i++)
		for(int md =0;md<m;md++)
			if(dp[i][md])
				for(int d =0;d<dig.size();d++)
					if(!((1<<d)&i))
						dp[i | (1<<d)][(md*10+dig[d])%m] += dp[i][md];
		
	
	
	lli ans = dp[(1<<n)-1][0];
	for(int d=0,c=0;d<10;d++,c=0)
		for(int i=0;i<dig.size();i++)
			if(dig[i] == d)
				c++, ans /= c;
				
	cout<<ans<<endl;	
}
int main()
{
	cin>>n>>m;
	lli tmp = n;
	while(n>0)
	{
		dig.pb(n%10);
		n /= 10;	
	}
	n = tmp;
	sort(dig.begin(),dig.end());
	findans();
}
