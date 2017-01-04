//21:25
#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
lli mem[17][101];

lli dp(int n,int k)
{
	if(k> (n*(n-1))/2)
		return 0;
	if(k==0)
		return 1;
	if(mem[n][k])
		return mem[n][k];
	lli ret = 0;
	for(int i=0;i<=min(n-1,k);i++)
		ret += dp(n-1,k-i);
	mem[n][k] = ret;
	
	return ret;
}

int main()
{
	int t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		cout<<dp(n,k)<<endl;
	}
}
