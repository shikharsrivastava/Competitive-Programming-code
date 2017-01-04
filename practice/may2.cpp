//21:45
#include<bits/stdc++.h>
using namespace std;
int n,m;
long long int a[100002];
bool cansolve(long long int k)
{
	long long int time;
	int day=0,i=1;
	while(i<=n)
	{
		time = 0;		
		while(i <= n && a[i] <= k-time)
		{
			time +=a[i];
			i++;
		}
		if(time == 0)
		return false;
		day++;
	}
	if(day <= m)
	return true;
	return false;
}

int main()
{
	long long int mx=1;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		mx = max(mx,a[i]);
	}
	
	long long int s,e,m;
	s = mx,e=100000000000000001;
	while(s<e)
	{
		m=(s+e)/2;
		//printf("S = %lld , e = %lld , m = %lld\n",s,e,m);
		if(cansolve(m))
		e=m-1;
		else
		s=m+1;
	}
	if(cansolve(s))
	printf("%lld\n",s);
	else
	printf("%lld\n",s+1);
}
