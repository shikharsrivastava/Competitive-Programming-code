#include<bits/stdc++.h>
#define MOD 1000000007
#define pro(a,b) (((a)*(b))%MOD)
typedef long long int lli;
using namespace std;

lli pw(lli a,lli b)
{
	lli ans =1;
	while(b>0)
	{
		if(b%2 == 1)
		ans = (ans * a) % MOD;
		a = (a*a) % MOD;
		b /= 2;
	}
	return ans;
}
lli modmulin(lli a)
{
	return pw(a,MOD-2);
}

int main()
{
	lli k,ans;
	int c,temp,n;

	scanf("%d %lld",&n,&k);
	/*for(int i=1;i<=n;i++)
	{
		scanf("%d",&c);
		while(c--)
		scanf("%d",&temp);
	}*/

	if(n == 4)
	{
		ans =pro(pro(pro(pro(k,(k+1)),(k+2)),(k+3)),modmulin(24));
	}
	else if(n == 6)
	{
		lli k2 = pw(k,2);
		ans = pro(pro(pro(pro(k,k+1),k2+k+2),k2+k+4),modmulin(48));
	}
	else if(n == 8)
	{
		lli k2 = pw(k,2) , k4 = pw(k,4) , k6 = pw(k,6) , k8 = pw(k,8);
		
		ans =pro( pro(k2,20) + pro(k4,21) + pro(k6,6) + k8 , modmulin(48));
	}
	else if(n==12)
	{
		lli k2 = pw(k,2) , k4 = pw(k,4) , k6 = pw(k,6) , k8 = pw(k,8);
	
		ans = pro(pro(pro(k2,k2+1) , (k8-k6 + 16*k4 + 44)%MOD) , modmulin(120));
	}
	else if(n == 20)
	{
		lli k2 = pw(k,2) , k6 = pw(k,6) , k8 = pw(k,8) , k10 = pw(k,10) , k18 = pw(k,18);
		ans = pro(pro(k2, (k18 + 15*k10 + 16* k8 + 20*k6 + 44*k2 + 24)%MOD) , modmulin(120));
	}
	
	printf("%lld\n",ans);
}
