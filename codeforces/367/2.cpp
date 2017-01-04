#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,q;
	scanf("%d",&n);
	int p[n+1];
	for(int i=1;i<=n;i++)
	scanf("%d",&p[i]);	
	scanf("%d",&q);
	int m[q+1];
	for(int i=1;i<=q;i++)
	scanf("%d",&m[i]);
	
	sort(p+1,p+n+1);
	for(int i=1;i<=q;i++)
	{
		int ans = upper_bound(p+1,p+n+1,m[i]) - (p+1);
		printf("%d\n",ans);
	}
	
}
