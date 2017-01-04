//22:35
#include<bits/stdc++.h>
using namespace std;
#define MOD 100000000;
typedef long long lli;
struct range
{
	int l,r;
	bool operator<(range &b)
	{
		if(r == b.r)
			return l<b.l;
		return r<b.r;
	}
};
int cnt(lli num)
{
	int ret = 0;
	while(num>0)
	num/=10 , ret++;	
	return ret;
}
int n;

int lb(int *a,int val,int e)
{
	
	int s =1;
	if(e<s)
		return 0;
	while(s<e)
	{
		int m =(s+e+1)>>1;
		if(a[m] <= val)
			s = m;
		else
			e = m-1;
	}
	if(a[s]>val)
		return 0;
	return s;
}
int main()
{
	while(true)
	{
		cin>>n;
		if(n == -1)
			break;
		range r[n+1];
		int en[n+1];

		for(int i=1;i<=n;i++)
		{
			cin>>r[i].l>>r[i].r;
			en[i] = r[i].r;
		}
	
		sort(r+1,r+n+1);
		sort(en+1,en+n+1);
	
		lli dp[n+1];
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			// taking this seg
			int prevs = lb(en,r[i].l,i-1);
			dp[i] = (dp[i] + 1+dp[prevs]) % MOD;
			// not taking this seg
			dp[i] = (dp[i] + dp[i-1])%MOD;

		}
		int len = cnt(dp[n]);
		if(len == 8)
			cout<<dp[n]<<endl;
		else
		{
			for(int i=1;i<=8-len;i++) cout<<"0";
			cout<<dp[n]<<endl;
		}
	}
	return 0;
}

