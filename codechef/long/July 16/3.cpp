#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
	int t,n,a[10002],b[10002];
	scanf("%d",&t);
	while(t--)
	{
		lli sum = 0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{scanf("%d",&b[i]); sum+=b[i];}
		for(int i=1;i<=n;i++)
		{scanf("%d",&a[i]); sum+=a[i];}
		int num = sum / n;
		if(((lli)n*num) != sum)
		{printf("-1\n");continue;}
		b[n+1] = 0;
		int c = 0;
		bool f =true;
		for(int i=1;i<=n;i++)
		{
			a[i] += c;
			if(a[i] == num)
			c = b[i];
			else if(a[i] + b[i] == num)
			b[i] = 0, c = 0;
			else if(a[i] + b[i+1] == num)
			b[i+1] = 0 , c = b[i];
			else if (a[i] + b[i] + b[i+1] == num)
			b[i] = b[i+1] = 0 , c = 0 ;
			else
			{f = false ; break;}
		}
		if(f)
		printf("%d\n",num);
		else
		printf("-1\n");
	}
}
