
#define MOD 1000000007
#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;

lli power(int a,int b)
{
	int ans = 1;
	while(b >0)
	{
		if(b%2 == 1)
		ans = ((lli)ans * a) % MOD;
		a = ((lli)a * a) %MOD;
		b/=2;
	}
	return ans;
}

int modmulin(int a)
{
	return power(a,MOD-2);
}

int main()
{
	int t,n,k,a,zc,ans;
	int * fact;
	scanf("%d",&t);
	while(t--)
	{
		zc = ans = 0 ;
		scanf("%d %d",&n,&k);
		fact = (int*)calloc(n+1,sizeof(int));
		fact[0] = 1;
		for(int i=1;i<=n;i++)
		{
			fact[i] = ((lli)i*fact[i-1])%MOD;
			scanf("%d",&a);
			if(a == 0)
			zc++;
		}
		if(zc >0)
		{
			n = n-zc;
			ans++; //No element changes
			for(int i=1;i<= min(n,k);i++)
			ans = (ans + ((lli)fact[n] * modmulin(((lli)fact[i]*fact[n-i])%MOD))%MOD) %MOD;	
		}
		else
		{
			if(k%2 == 0)
			{
				ans++;	//No element changes
				for(int i=2;i<=min(n,k);i+=2)
				ans = (ans + ((lli)fact[n] * modmulin(((lli)fact[i]*fact[n-i])%MOD))%MOD) %MOD;	
			}
			else
			{
				for(int i=1;i<=min(n,k);i+=2)
				ans = (ans + ((lli)fact[n] * modmulin(((lli)fact[i]*fact[n-i])%MOD))%MOD) %MOD;
			}
		}
		printf("%d\n",ans);
	}
}


