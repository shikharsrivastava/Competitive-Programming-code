//22 : 08
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[5],sm = 0,ans = 1000000000,m;
	for(int i=0;i<5;i++)
	{scanf("%d",&a[i]);sm+=a[i];}
	
	int c = 0;
	for(int i=0;i<5;i++)
	{
		c = 0,m=0;
		for(int j = 0;j<5;j++)
		{if(a[j] == a[i])
		c++;}
		if(c >=2)
		m  = (min(c,3))*a[i];
		ans = min(ans,sm-m);
	}
	printf("%d\n",ans);
}
