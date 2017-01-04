#include<cstdio>
#include<cstdlib>
#include<cmath>
#define max(a,b) a>b?a:b
int lcm(int*,int**,int,int);
int main()
{
int t,n,k,a,b,m,max=0,multiplier,ans;
int primes[168]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997};
double frac1,frac2;
int*c,*d;
scanf("%d",&t);
scanf("%d %d",&n,&k);
scanf("%d %d %d",&a,&b,&m);
 
c=(int*)calloc(t+1,sizeof(int));
d=(int*)calloc(t+1,sizeof(int));
 
for(int i=2;i<=t;i++)
scanf("%d",&c[i]);
 
for(int i=2;i<=t;i++)
scanf("%d",&d[i]);
 
 

// calculating factors of each number
 
int** factors=(int**)calloc(m+1,sizeof(int));
for(int i=0;i<m+1;i++)
factors[i]=(int*)calloc(m+1,sizeof(int));
 
int pow_count,prm_no,number,limit;
factors[1][1]=1;
for(int i=2;i<=m;i++)
{	
	for(int j=0;(j<168) && primes[j]<=i;j++)
	{	//printf("i = %d j = %d Primes = %d\n",i,j,primes[j]);
		pow_count=0;
		prm_no=primes[j];
		number=i;
		while(number%prm_no==0)
		{
		number=number/prm_no;
		pow_count++;
		}
		factors[i][primes[j]]=pow_count;

	}

}
 
ans=lcm(primes,factors,n,k);
printf("%d\n",ans);
 
for(int i=2;i<=t;i++)
{
n=1+((long long)a*ans+c[i])%m;
k=1+((long long)b*ans+d[i])%n;
ans=lcm(primes,factors,n,k);
printf("%d\n",ans);
}
return 0;
}
 
 
 
int lcm(int* primes,int** factors,int n,int k)
{
int *lcm_sieve=(int*)calloc(n+1,sizeof(int));
for(int i=n-k+1;i<n+1;i++)
{
for(int j=0;(j<168) && primes[j]<=i;j++)
	lcm_sieve[primes[j]]=max(lcm_sieve[primes[j]],factors[i][primes[j]]);
	
}
int ans=1;
for(int i=0;(i<168) && primes[i]<=n;i++)
ans=(ans*(long long)pow(primes[i],lcm_sieve[primes[i]]))%1000000007;
free(lcm_sieve);
 
return ans;
}
