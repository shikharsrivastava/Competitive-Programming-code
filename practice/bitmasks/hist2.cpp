// Travelling salesman problem
#include<bits/stdc++.h>
using namespace std;
int a[16],n,hash[16][1<<16],sumhash[16][1<<16];
int dp(int pos,int mask)
{
		if(mask == 0)
			{hash[pos][mask] = 2+2*a[pos] , sumhash[pos][mask] = 1;}
		

		if(hash[pos][mask] >0)
			return hash[pos][mask];
		
		int peri = 2 + 2*a[pos];
		int mx = 0;
		for(int i=0;i<n;i++)
			if((mask>>i)&1)
				{
					int val = peri+dp(i,mask ^ (1<<i))-2*min(a[pos],a[i]);
					if(val > mx)
					sumhash[pos][mask] = sumhash[i][mask ^ (1<<i)] , mx = val;
					else if(val == mx)
					sumhash[pos][mask] += sumhash[i][mask ^ (1<<i)];
				}
			
		hash[pos][mask] = mx;
		return hash[pos][mask];
}

int main()
{
	scanf("%d",&n);
	while(n != 0)
	{	
		for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		
		int bit = (1<<n)-1;
		int ans = 0;
		memset(hash,0,sizeof(hash));
		memset(sumhash,0,sizeof(sumhash));
		for(int i=0;i<n;i++)
		dp(i,(bit ^ (1<<i)));
		
		int mx=0,perm=0;
		for(int i=0;i<n;i++)
		{
			if(hash[i][bit ^ (1<<i)] > mx)
			mx = hash[i][bit ^ (1<<i)] , perm = sumhash[i][bit ^ (1<<i)];
			else if(hash[i][bit ^ (1<<i)] == mx)
			perm += sumhash[i][bit ^ (1<<i)];
		}
		printf("%d %d\n",mx,perm);
		scanf("%d",&n);
		
	}
}
