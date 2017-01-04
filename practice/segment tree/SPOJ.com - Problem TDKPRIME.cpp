/*
	In bitwise sieve we compress the information in form of bits in 32 bit compartments (unsigned)
	A 32 bit number represents 32 different integers.The bit at that psition is 1 if
	that number is prime and 0 if it is not prime.So to find prime numbers till range MAX
	We only need MAX/32 32 bit integers.So our array is prime[MAX/32].The 32 bits of prime[0]
	represent the integers 1,2,3,4......32 and bit positions 31,30,29,28.......0 respectively
	An integer is prime if the corresponding bit is on(1) ,else it is not prime.In the begining
	we assume all numbers to be prime and start from the first prime numner 2 .In the sieve operation we use
	Bit manipulation to switch off all the bits corresponding to numbers which are multiples of prime,and we 
	make functions to check weather a number is prime by checking its corresponding bit.
*/


#include<cstdio>
#include<cstdlib>
#include<cmath>
#define MAX 86029000


unsigned *prime;

// function to check weather a number is prime
bool isprime(int n)
{
return prime[n/32]&(1<<(32-n));
}



int main()
{
// array of compressed data
prime=(unsigned*)calloc(MAX/32+2,sizeof(unsigned));
// array of kth prime number
int *p=(int*)calloc(5000100,sizeof(int));
// checking till square root
int limit=ceil(sqrt(MAX));
int k=1,q;

for(int i=0;i<MAX/32;i++)
prime[i]=0xffffffff;

prime[0]&=~(1<<(32-1));
for(int i=2;i<=limit;i++)
{	// checking weather this number is prime i.e still on
	if(prime[i/32]&(1<<(32-i)))
		{
		// storing the prime number
		p[k++]=i;
		for(int j=i*i;j<=MAX;j+=i)
			// switching off bits of all multiples of numner i which is found to be prime
			prime[j/32]&=~(1<<(32-j));
		}

}
// storiing prime numbers ahead of LIMIT
for(int i=limit;i<MAX;i++)
{
if(isprime(i))
p[k++]=i;
}
// answering querries
scanf("%d",&q);
while(q--)
{
scanf("%d",&k);
printf("%d\n",p[k]);
}
free(prime);
free(p);
}


