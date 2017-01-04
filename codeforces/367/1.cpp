#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,n;
	scanf("%d %d %d",&a,&b,&n);
	int x[n+1],y[n+1],s[n+1];
	for(int i=1;i<=n;i++)
	scanf("%d %d %d",&x[i],&y[i],&s[i]);
	
	double time = 1000000000;

	for(int i=1;i<=n;i++)
	{
		double t = sqrt(pow((double)a-x[i],2) + pow((double)b-y[i],2))/(s[i]);
		time = min(time,t);
	}
	printf("%lf\n",time);
	
}
