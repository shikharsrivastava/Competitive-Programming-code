/*
	We create 32 bitarrays (0..31) for all bits of all elements like
	
		31 30 ................................... 4 3 2 1 0
element 1	0  0 .................................... 1 0 1 0 0
element 2	
element 3
.........
.........
.........
.........
element n

And then we make BIT for each of the 32 bits for ranges 1..n
This way we can count the number of kth bits set in range l..r of the array
	
	Then we make formula for XOR OR AND
	If x kth bits are set and y kth bits are reset in range l..r
	Sum of range taking two elements at a time due to kth bit in range l...r for each operation will be

	AND	x*(x-1)/2* 2^k
	OR	(2*y+(x-1))*x/2 *2^k
	XOR 	x*y *2^k

	This formula can be easily derieved

*/

#include<bits/stdc++.h>
typedef long long int lli;
int n,q,**bit;
void update(int bn,int val,int id)
{
	while(id<=n)
	{
	bit[bn][id]+=val;
	id+=id&-id;
	}
}

int sum(int bn,int id)
{
	int ans=0;
	while(id>0)
	{
	ans+=bit[bn][id];
	id-=id&-id;
	}
	return ans;
}

int main()
{
	int k,c,id,num,l,r,x,y;
	lli ans;
	char op[5];
	scanf("%d %d",&n,&q);
	int* a=new int[n+1];
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	
	bit=(int**)calloc(33,sizeof(int*));

	for(int i=0;i<=32;i++)
	bit[i]=(int*)calloc(n+1,sizeof(int));
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=31;j++)
		{
			k=(a[i]>>j)&1;
			update(j,k,i);
		}
	}
	
	for(int i=1;i<=q;i++)
	{
		ans=0;
		scanf("%d",&c);
		if(c==1)
		{
			scanf("%d %d",&x,&id);
			for(int j=0;j<=31;j++)
			{
			k=(x>>j)&1;
			num=sum(j,id)-sum(j,id-1);
			update(j,k-num,id);
			}
		}
		else
		{
			scanf("%s %d %d",op,&l,&r);
			if(op[0]=='A')
			{
				for(int j=0;j<=31;j++)
				{
				x=sum(j,r)-sum(j,l-1);
				y=(r-l+1)-x;
				ans+=((lli)x*(x-1)/2)*(1<<j);				
				}	
			}
			else if(op[0]=='O')
			{
				for(int j=0;j<=31;j++)
				{
				x=sum(j,r)-sum(j,l-1);
				y=(r-l+1)-x;
				ans+=((lli)x*(2*y+x-1)/2)*(1<<j);				
				}			
			}								
			else
			{
				for(int j=0;j<=31;j++)
				{
				x=sum(j,r)-sum(j,l-1);
				y=(r-l+1)-x;
				ans+=(lli)x*y*(1<<j);				
				}			
			}
			printf("%lld\n",ans);
		}
	}
	for(int i=0;i<=32;i++)
	free(bit[i]);
	free(bit);
	delete(a);
	return 0;


}
