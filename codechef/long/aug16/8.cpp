#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
	int n;
	scanf("%d",&n);
	int a[n+1];
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);

	lli sum = 0;
	for(int i=1;i<=n;i++)
	{
		int mx = a[i];
		for(int j=i+1;j<=n;j++)
		{
			mx = max(mx,a[j]);
			if(((a[i] & a[j]) == a[i]) || ((a[i] & a[j]) == a[j]))
				sum += mx;
			
		}
	}
	printf("%lld\n",sum);
	return 0;
}
