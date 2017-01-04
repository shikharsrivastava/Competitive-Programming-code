#include<cstdio>
#include<cstdlib>

long long int sum(long long int a)
{
long long int sum,n;
	while(a>9)
{
	sum=0;
	n=a;
	while(n>0)
	{
	sum=sum+n%10;
	n=n/10;
	}
	a=sum;
}
return a;

}

int main()
{
int t,cons;

long long a,d,sm[10],first_elem,stride;
long long int l,r,n,ans;

scanf("%d",&t);
while(t--)
{
ans=0;
scanf("%lld %lld %lld %lld",&a,&d,&l,&r);
cons=0;
n=r-l+1;
for(int i=1;i<=9;i++)
{
sm[i]=sum(a+((i-1)*d));
cons+=sm[i];
//printf("sum[%d] = %lld\n",i,sm[i]);
}

if(l%9==0)
first_elem=9;
else
first_elem=l%9;

ans=(n/9)*cons;

stride=n%9;

while(stride>0)
{
ans+=sm[first_elem];
stride--;
first_elem++;
if(first_elem>9)
first_elem=1;
}

printf("%lld\n",ans);


}

}
