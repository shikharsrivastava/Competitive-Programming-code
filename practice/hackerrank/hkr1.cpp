//22:55
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int aa=0,ba=0;
	int a[3],b[3];
	for(int i=0;i<3;i++)
	scanf("%d",&a[i]);
	for(int i=0;i<3;i++)
	scanf("%d",&b[i]);

	for(int i=0;i<3;i++)
	{
		if(a[i] >b[i])
		aa++;
		else if(a[i] < b[i])
		ba++;
	}
	printf("%d %d\n",aa,ba);
	return 0;

}
