#include<bits/stdc++.h>
typedef long long int lli;

lli *bit1,*bit2;
int n;
void update(lli *bit,int ind,lli val)
{
	while(ind<=n)
	{
	bit[ind]+=val;
	ind+=ind & -ind;
	}
}

lli sum(lli* bit,int ind)
{
	lli ans=0;
	while(ind>0)
	{
	ans+=bit[ind];
	ind-=ind &-ind;
	}
	return ans;
}
int main()
{
	int t,x,p,q,c;
	lli v;
	scanf("%d",&t);
	while(t--)
{
	scanf("%d %d",&n,&c);
	 bit1=(lli*)calloc(n+1,sizeof(lli));
	 bit2=(lli*)calloc(n+1,sizeof(lli));

	for(int i=1;i<=c;i++)
	{
		scanf("%d",&x);
		if(x==0)
	{
		scanf("%d %d %lld",&p,&q,&v);
		update(bit1,p,v);
		update(bit1,q+1,-v);
		
		update(bit2,p,(p-1)*v);
		update(bit2,q+1,-q*v);
	
	}
	else
	{
		scanf("%d %d",&p,&q);
		printf("%lld\n",(sum(bit1,q)*q - sum(bit2,q))-(sum(bit1,p-1)*(p-1)-sum(bit2,p-1)));
	}
	}
	free(bit1);
	free(bit2);
}
	
}
