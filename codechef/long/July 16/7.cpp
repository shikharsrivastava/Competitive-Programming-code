#include<bits/stdc++.h>
#define MOD 786433
using namespace std;
typedef long long int lli;
int main()
{
	int n,x,q;
	scanf("%d",&n);
	int a[n+2];
	for(int i=0;i<=n;i++)
	scanf("%d",&a[i]);
	scanf("%d",&q);
	while(q--)
	{
		int ans = 0;
		scanf("%d",&x);
		for(int i=n;i>=0;i--)
			ans = (a[i] + ((lli)x*ans % MOD))%MOD;
		printf("%d\n",ans);
	}
}
