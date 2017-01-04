/*
	Simple binary search 
*/
#include<bits/stdc++.h>
using namespace std;
int* a;
int last(int s,int e,int v)
{
	int m;
	while(s<e)
	{
		m=(s+e)/2;
		if(a[m]<= v)
		s=m+1;
		else
		e=m-1;
	}
	if(a[s]>v)
	return s-1;
	return s;
	
}

bool isthere(int s,int e,int v)
{
	if(s>e)
	return false;

	int m;
	while(s<e)
	{
		m=(s+e)/2;
		if(a[m]<v)
		s=m+1;
		else if(a[m]>v)
		e=m-1;
		else
		return true;
	}
	if(a[s] == v)
	return true;
	return false;
}
int main()
{
	int n,m,b1,b2,ind;
	while(scanf("%d",&n)!= EOF)
	{
	a=(int*)calloc(n+1,sizeof(int));
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	scanf("%d",&m);
	ind=last(1,n,m/2);
	for(int i=1;i<=ind;i++)
	{
		if(isthere(i+1,n,m-a[i]))
			b1=a[i],b2=m-a[i];		
		
	}
	printf("Peter should buy books whose prices are %d and %d.\n\n",b1,b2);
	free(a);	
	}
	
}
