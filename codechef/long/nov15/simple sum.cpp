#include<cstdio>
#include<cstdlib>
#include<cmath>
class Sieve
{
public:
bool checked;
int smallest_prime;
};
Sieve *sieve;


int gc()
{
	register int a=0;
	register char c;
	c=getchar_unlocked();
	while(c>47 && c<58)
	{
	a=a*10+c-48;
	c=getchar_unlocked();
	}
	return a;
}


long long int power(long long int a,long long int b)
{
	long long int answer=1;
	while(b>0)
	{
		if(b%2==1)
		answer=answer*a;
		a=a*a;
		b=b/2;
	}
	return answer;

}

long long int ans(int n)
{
double a,c;
long long int answer=1;
long long int k,prev;
prev=sieve[n].smallest_prime;
k=0;
while(n>1)
{
if(sieve[n].smallest_prime==prev)
k++;
else
{
a=power(prev,2*k)/(double)(prev+1);
c=(double)1/(prev+1);
answer*=round(a*prev+c);
prev=sieve[n].smallest_prime;
k=0;
continue;
}
n=n/sieve[n].smallest_prime;
}

if(k>0)
{
a=power(prev,2*k)/(double)(prev+1);
c=(double)1/(prev+1);
answer*=round(a*prev+c);
}
return answer;

}

int main()
{
int t,n,sq,div;
long long int m,*a;
sq=3162;
sieve=(Sieve*)calloc(10000001,sizeof(Sieve));

for(int i=1;i<=10000000;i++)
sieve[i].smallest_prime=i;


for(int i=2;i<=sq;i++)
{
	if(sieve[i].checked==1)
	continue;
	m=i;
	
	while(m*i <= 10000000)
	{
	if(sieve[m*i].smallest_prime==m*i)
	sieve[m*i].smallest_prime=sieve[i].smallest_prime;
	sieve[m*i].checked=1;
	m++;
	}

}


t=gc();
while(t--)
{
n=gc();
printf("%lld\n",ans(n));
}
free(sieve);
return 0;
}
