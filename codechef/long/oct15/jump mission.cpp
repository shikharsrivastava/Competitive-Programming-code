#include<cstdio>
#include<cstdlib>

int main()
{
int t,n,k;
int *p,*a,*h;
long long int *dp;

long long int sum=0,min;
scanf("%d",&n);
p=(int*)calloc(n+1,sizeof(int));
a=(int*)calloc(n+1,sizeof(int));
h=(int*)calloc(n+1,sizeof(int));
dp=(long long int*)calloc(n+1,sizeof(long long int));

for(int i=1;i<=n;i++)
scanf("%d",&p[i]);

for(int i=1;i<=n;i++)
scanf("%d",&a[i]);

for(int i=1;i<=n;i++)
scanf("%d",&h[i]);

dp[1]=a[1];
for(int i=2;i<=n;i++)
{	sum=0;
	min=1000000000000000000;
	for(int j=1;j<i;j++)
	{
	if(p[j]<p[i])
	{
	sum=dp[j]+(h[i]-h[j])*(h[i]-h[j])+a[i];
	if(sum<min)
	min=sum;
	}
	}
	dp[i]=min;
}
printf("%lld\n",dp[n]);
free(p);
free(a);
free(h);
free(dp);

}
