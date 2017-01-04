//25:50
#include<bits/stdc++.h>
using namespace std;

struct bit
{
	int *b;
	int n;
	bit()
	{
		b=(int*)calloc(1,sizeof(int));
	}
	void reset(int s)
	{
		n=s;
		free(b);
		b=(int*)calloc(n+1,sizeof(int));
	}
	void update(int p,int q,int v)
	{
		q++;
		while(p<=n)
		{
			b[p]+=v;
			p+=p&-p;
		}
		while(q<=n)
		{
			b[q]-=v;
			q+=q&-q;
		}
	}
	int get(int p)
	{
		int ans=0;
		while(p>0)
		{
			ans+=b[p];
			p-=p&-p;
		}
		return ans;
	}
};

int main()
{
	int n,l,r,upd;
	bit b;
	b.reset(100000);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&l,&r);
		printf("%d\n",b.get(l)+b.get(r));
		upd=b.get(l);
		b.update(l,l,-upd);
		upd=b.get(r);
		b.update(r,r,-upd);
		if(r-l>1)
		b.update(l+1,r-1,1);
	}	
}

