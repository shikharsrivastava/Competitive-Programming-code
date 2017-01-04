//21:40
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		sum+=a;
	}
	printf("%d\n",max(n,(int)ceil(sum/2.0)));
}
