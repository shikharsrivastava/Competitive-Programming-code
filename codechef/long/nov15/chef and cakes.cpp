#include<cstdio>
#include<cmath>
int gcd(int a,int b)
{
	int c;
	while(a%b>0)
	{
	c=a%b;
	a=b;
	b=c;
	}
return b;

}

int main()
{
int t,n,m,j,digit,stride,gc,elem;

scanf("%d",&t);
while(t--)
{
scanf("%d %d",&n,&m);
if(m==0)
{
	if(n==1)
	printf("Yes\n");
	else
	printf("No 1\n");
	continue;
}
else if(m==1)
{
	printf("Yes\n");
	continue;
}

else if(n%m==0)
{
	printf("No %d\n",n/m);
	continue;
}
j=n%m;
stride=m-j;

elem=1+stride;

gc=gcd(m,stride);
if(gc==1)
	printf("Yes\n");
else
	printf("No %d\n",(n/m)*(m/gc)+(m-elem)/gc+1);

}

}
