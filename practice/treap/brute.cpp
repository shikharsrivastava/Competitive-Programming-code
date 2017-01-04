#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,q,a,b,c,t,ans;
	scanf("%d",&n);
	int arr[n+1];
	for(int i =1;i<=n;i++)
		scanf("%d",&arr[i]);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&t);
		if(t == 0)
		{
			ans = 0;
			scanf("%d %d %d",&a,&b,&c);
			for(int i=a;i<=b;i++)
			if(arr[i] >= c) ans++;
			printf("%d\n",ans);
		}
		else
		{
			scanf("%d %d",&a,&b);
			arr[a] = b;
		}
	}
}
