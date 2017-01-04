#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int lli;
typedef double db;

int number(db n)
{
	n = n -(int)n;
	return floor(pow(10,n));
}

int power(int a,int b)
{
	int ans = 1;
	while(b>0)
	{
		if(b%2 == 1)
		ans = ((lli)ans * a) % MOD;
		a = ((lli)a * a) %MOD;
		b /= 2;
	}
	return ans;
}
int modmulin(int a)
{
	return power(a,MOD-2);
}
int first(lli n)
{
	while(n>0)
	{	
		if(n/10 == 0)
		return (int)n;
		n/=10;
	}
}
int main()
{
	int n,sqn,q,c,p,f,r;
	scanf("%d",&n);
	int a[n+1];
	if(n<=10)
	{
		for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d",&c);
			if(c == 1)
			{
				scanf("%d %d",&p,&f);
				a[p] = f;
			}
			else
			{
				scanf("%d",&r);
				lli pro = a[1];
				for(int i=1+r;i<=n;i+=r)
				pro = pro * a[i];
				printf("%d %d\n",first(pro),(int)(pro%MOD));
			}
			
		}
	}
	else
	{
		sqn = sqrt(n);
		db ans[sqn+1];
		int md[sqn+1];
		for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		for(int i=1;i<=sqn;i++)
		{
			int mul = 1;
			md[i] = 1;
			ans[i] = 0;
			while(i*mul < n)
			{
				ans[i] += log10(a[i*mul]);	
				md[i] = ((lli)md[i] * a[i*mul])%MOD;
				mul++;
			}
		}


		scanf("%d",&q);
		while(q--)
		{
			scanf("%d",&c);
			if(c == 1)
			{
				scanf("%d %d",&p,&f);
				p--;
		
					db sub = log10(a[p]);
					db add = log10(f);
					int prev = a[p];
					a[p] = f;

					for(int i=1;i<=sqrt(p);i++)
					{	
						if(p % i == 0)
						{
							ans[i] += add;
							ans[i] -= sub;
							md[i] = ((lli)md[i] * f)%MOD ;
							md[i] = ((lli)md[i] * modmulin(prev)) %MOD;
							if(i != (p/i) && (p/i) <=sqn)
							{
								ans[(p/i)] += add ;
								ans[(p/i)] -=sub;
								md[(p/i)] = ((lli)md[(p/i)] * f)%MOD ;
								md[(p/i)] = ((lli)md[(p/i)] * modmulin(prev)) %MOD;					
							}
						}
					
					}
			}
			else
			{
				scanf("%d",&r);
				if(r>sqn)
				{
					db as = log10(a[0]);
					int pro = a[0];
					for(int i=r;i<n;i+=r)
					as += log10(a[i]) , pro = ((lli)pro * a[i])%MOD;
					printf("%d %d\n",number(as),pro);
				}
				else
				printf("%d %d\n",number(ans[r]+log10(a[0])),(int)(((lli)md[r]*a[0])%MOD));
			
			}
		}
	}
	
}
