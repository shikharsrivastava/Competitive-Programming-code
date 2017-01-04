//17:00
#include<bits/stdc++.h>
using namespace std;

int lowerbound(int *a,int s,int e,int v)
{
	int m;
	while(s<e)
	{
		m=(s+e)/2;
		if(a[m]>=v)
		e=m-1;
		else
		s=m+1;
	}
	if(a[s] != v)
	return s+1;
	else
	return s;
}

int upperbound(int *a,int s,int e,int v)
{
	int m;
	while(s<e)
	{
		m=(s+e)/2;
		if(a[m]<=v)
		s=m+1;
		else
		e=m-1;
	}
	if(a[s] != v)
	return s-1;
	else
	return s;
}

int main()
{
	int n;
	int *a,*b,*c,*d;
	scanf("%d",&n);
	a=(int*)calloc(n+1,sizeof(int));
	b=(int*)calloc(n+1,sizeof(int));
	c=(int*)calloc(n+1,sizeof(int));
	d=(int*)calloc(n+1,sizeof(int));
	for(int i=1;i<=n;i++)
	scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
	
	int *sa=(int*)calloc((n+1)*(n+1),sizeof(int));
	int *sb=(int*)calloc((n+1)*(n+1),sizeof(int));

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
				sa[n*(i-1)+j]=a[i]+b[j];
		for(int j=1;j<=n;j++)
				sb[n*(i-1)+j]=c[i]+d[j];	
	
	}
		

	sort(sa+1,sa+(n*n)+1);
	sort(sb+1,sb+(n*n)+1);


	long long int ans=0;
	int lb,ub;
	for(int i=1;i<=n*n;i++)
	{
		lb=lowerbound(sb,1,n*n,-sa[i]);
		if(sb[lb] != -sa[i])
		continue;
		ub=upperbound(sb,1,n*n,-sa[i]);
		ans+=(ub-lb+1);	
	}
	printf("%lld\n",ans);
	free(a);
	free(b);
	free(c);
	free(d);
	free(sa);
	free(sb);	

}
