#include<cstdio>
#include<cstdlib>
#include<cmath>
#define max(a,b) a>b?a:b
int lcm(int*,int**,int,int);
int count;
int main()
{

int t,n,o,a,b,m,k,newnum,max=0,multyplier,ans;
scanf("%d",&m);
int *primes=(int*)calloc(m+1,sizeof(int));


/*int*c,*d;
scanf("%d",&t);
scanf("%d %d",&n,&k);
scanf("%d %d %d",&a,&b,&m);
c=(int*)calloc(t+1,sizeof(int));
d=(int*)calloc(t+1,sizeof(int));
 
for(int i=2;i<=t;i++)
scanf("%d",&c[i]);
 
for(int i=2;i<=t;i++)
scanf("%d",&d[i]);*/

/*Finding all primes till m*/
		count=0;
		int l=1;
		int u=m;
		char *sieve=(char*)calloc((u-l+2),sizeof(char));
		char *checksieve=(char*)calloc(sqrt(u)+1,sizeof(char));
		int multyplier_checksieve=1;

		for(int i=2;i<=sqrt(u);i++)
		{	
			if(checksieve[i] =='f')
			continue;
			
			multyplier_checksieve=i;
			while(i*multyplier_checksieve <= sqrt(u))
			{
				checksieve[i*multyplier_checksieve]='f';
				multyplier_checksieve++;
			}
			
			multyplier=ceil((float)l/i);
			
			if(multyplier==1)
			multyplier++;

			while(i*multyplier<=u)
			{
				sieve[i*multyplier-l+1]='f';
				multyplier++;
				
			}	
		}
		
		for(int i=2,j=0;i<=u-l+1;i++)
		if(sieve[i]!='f')
		{
		primes[j]=i;
		count++;
		j++;		
		}	
		free(sieve);
		free(checksieve);
/*All primes stored in primes array*/




 

// calculating factors of each number
 printf("M = %d\n",m);
int** factors=(int**)calloc(m+1,sizeof(int));
for(int i=0;i<m+1;i++)
factors[i]=(int*)calloc(m+1,sizeof(int));

sieve=(char*)calloc(m+1,sizeof(char));
int pow_count,prm_no,number,limit;
factors[1][1]=1;
for(int i=2;i<=m;i++)
{	
	
	if(sieve[i]=='t')
	continue;
	printf("Count = %d\n",count);
	for(int j=0;(j<count) && primes[j]<=i;j++)
	{	printf("i = %d j = %d Primes = %d\n",i,j,primes[j]);
		pow_count=0;
		prm_no=primes[j];
		number=i;
		while(number%prm_no==0)
		{
		number=number/prm_no;
		pow_count++;
		}
		factors[i][primes[j]]=pow_count;
		printf("Here\n");

	}
	printf("here\n");
	
	sieve[i]='t';
	for(int j=2;j<=i;j++)
	{
	newnum=j*i;
	if(newnum>m)
	break;
	for(o=0;(o<count) && primes[o]<=j;o++)
	factors[newnum][primes[o]]=factors[i][primes[o]]+factors[j][primes[o]];
	for(;(o<count) && primes[o]<=j;o++)
	factors[newnum][primes[o]]=factors[i][primes[o]];
	sieve[newnum]='t';
	
	}


}

for(int i=1;i<=m;i++)
{
printf("Number = %d ",i);
for(int j=0;(j<count) && primes[j]<=i;j++)
printf("%d ^ %d ",primes[j],factors[i][primes[j]]);
printf("\n");
}
 
/*ans=lcm(primes,factors,n,k);
printf("%d\n",ans);
 
for(int i=2;i<=t;i++)
{
n=1+((long long)a*ans+c[i])%m;
k=1+((long long)b*ans+d[i])%n;
ans=lcm(primes,factors,n,k);
printf("%d\n",ans);
}*/
return 0;
}
 
 
 
int lcm(int* primes,int** factors,int n,int k)
{
int *lcm_sieve=(int*)calloc(n+1,sizeof(int));
for(int i=n-k+1;i<n+1;i++)
{
for(int j=0;(j<9592) && primes[j]<=i;j++)
	lcm_sieve[primes[j]]=max(lcm_sieve[primes[j]],factors[i][primes[j]]);
	
}
int ans=1;
for(int i=0;(i<9592) && primes[i]<=n;i++)
ans=(ans*(long long)pow(primes[i],lcm_sieve[primes[i]]))%1000000007;
free(lcm_sieve);
 
return ans;
}
