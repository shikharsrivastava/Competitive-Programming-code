
#include<bits/stdc++.h>
using namespace std;
struct bit
{
	int *b;
	int n;
	bit(int s)
	{
		n=s;
		b=(int*)calloc(n+1,sizeof(int));	
	}
	void update(int p,int v=1)
	{
		while(p<=n)
		b[p]+=v,p+=p&-p;
	}
	int sum(int p)
	{
		int ans=0;
		while(p>0)
		ans+=b[p],p-=p&-p;
		return ans;
	}
};

int main()
{
	int n;
	scanf("%d",&n);
	int a[n+1],p[n+1];
	long long int ans=0,finalans;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		p[a[i]]=i;
	}	

	bit b(n);
	for(int i=n;i>0;i--)
	{
		ans+=b.sum(p[i]);
		b.update(p[i]);
	}
	
	finalans=ans;
	for(int i=1;i<n;i++)
	{
		ans-=(p[i]-1);
		ans+=n-p[i];
		finalans=min(ans,finalans);
	}
	printf("%lld\n",finalans);
	
}
