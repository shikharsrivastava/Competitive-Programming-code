#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int* primes;
int lcm(int,int);
int main()
{
int t,i,j,n,k,a,b,m,max=0,multiplier,ans;
primes=(int*)calloc(169,sizeof(int));
double frac1,frac2;
int*c,*d;
scanf("%d",&t);
scanf("%d %d",&n,&k);
scanf("%d %d %d",&a,&b,&m);

c=(int*)calloc(t+1,sizeof(int));
d=(int*)calloc(t+1,sizeof(int));

for(i=2;i<=t;i++)
scanf("%d",&c[i]);

for(i=2;i<=t;i++)
scanf("%d",&d[i]);


// calculating f[n][1]
int **f=(int**)calloc(1001,sizeof(int**));
for(i=0;i<=1000;i++)
{
f[i]=(int*)calloc(1001,sizeof(int));
f[i][1]=i;
}

// calculating f[n][k]
/*for(i=1;i<=1000;i++)
for(j=2;j<=i;j++)
{
frac1=(float)1/f[i-1][j-1];
frac2=(float)1/f[i][j-1];
f[i][j]=floor(1/(frac1-frac2));
}*/
// calculating all primes before 1000
char* sieve=(char*)calloc(10001,sizeof(char));
for(i=2;i<=sqrt(1000)+1;i++)
{
	if(sieve[i]=='f')
	continue;
	
	multiplier=i;
	while(i*multiplier<=1000)
	{
	sieve[i*multiplier]='f';
	multiplier++;
	}
}
for(i=2,j=0;i<=1000;i++)
{	if(sieve[i] !='f')
	{
	primes[j]=i;
	j++;
	}
}
ans=lcm(n,k);
printf("%d\n",ans);

for(i=2;i<=t;i++)
{
n=1+(a*ans+c[i])%m;
k=1+(b*ans+d[i])%n;
ans=lcm(n,k);
printf("%d\n",ans);
}
return 0;
}

int lcm(int n,int k)
{
int pow_count,prm_no,number,i,j;
int* powers=(int*)calloc(1001,sizeof(int));
for(i=n-k+1;i<n+1;i++)
{
	for(j=0;primes[j]<=i;j++)
	{	
		pow_count=0;
		prm_no=primes[j];
		number=i;
		while(number%prm_no==0)
		{
		number=number/prm_no;
		pow_count++;
		}
		if(pow_count>powers[prm_no])
		powers[prm_no]=pow_count;
	}
}

int ans=1;
for(i=0;i<169;i++)
ans=(ans*(long long)pow(primes[i],powers[primes[i]]))%1000000007;

free(powers);

return ans;
}

