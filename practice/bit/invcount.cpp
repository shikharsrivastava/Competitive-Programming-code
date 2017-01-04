//16:11
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
	
	void update(int pos,int val)
	{
		while(pos<=n)
		{
			b[pos]+=val;
			pos+=pos & -pos;
		}
	}
	int sum(int pos)
	{
		int ans=0;
		while(pos>0)
		{
			ans+=b[pos];
			pos-=pos & -pos;
		}
		return ans;
	}
	void reset()
	{
		free(b);
		b=(int*)calloc(n+1,sizeof(int));	
	}
		
};
int main()
{
	int t,n,*a;
	long long int ans;
	bit b(10000001);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		b.reset();
		ans=0;
		a=(int*)calloc(n+1,sizeof(int));

		for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);

			
		for(int i=n;i>0;i--)
		{
			b.update(a[i],1);
			ans+=b.sum(a[i]-1);
		}
		printf("%lld\n",ans);
		free(a);
	}
}
