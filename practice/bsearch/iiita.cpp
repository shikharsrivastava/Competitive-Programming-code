//19:00

#include<bits/stdc++.h>
using namespace std;
int *a;
int people(int s,int e,int v)
{
	int ans=0;
	for(int i=s;i<=e;i++)
	ans+=a[i]/v;
	return ans;
}

int main()
{
	int n,t,s,m,e,k,mx;
	scanf("%d",&t);
	while(t--)
	{
	mx=0;
	scanf("%d %d",&n,&k);
	a=(int*)calloc(n+1,sizeof(int));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);	
	}
	
	sort(a+1,a+n+1);
	
	s=1,e=mx;	
	while(s<e)
	{
		m=(s+e)/2;
		if(people(1,n,m)>=k)
		s=m+1;
		else
		e=m-1;
	}
	if(people(1,n,s)<k)
	printf("%d\n",s-1);
	else
	printf("%d\n",s);
	}
	return 0;	
}
