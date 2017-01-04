//16:24
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
	
	void update(int pos,int v)
	{
		while(pos<=n)
		{
		b[pos]+=v;
		pos+=pos & -pos;
		}
	}
	int sum(int pos)
	{
	int ans=0;
	while(pos >0)
	{
		ans+=b[pos];
		pos-=pos & -pos;
	}
	return ans;
	}	

	void reset(int s)
	{
	free(b);	
	n=s;
	b=(int*)calloc(n+1,sizeof(int));
	}
	
	int zero(int pos)
	{
		return pos-sum(pos);
	}
	/*Returns the index i such that number of zeros from in bit[s...i] = v*/
	int find(int s,int e,int v)
	{
		int st=s,m;
		while(s<e)
		{

			m=(s+e)/2;
			if(zero(m)-zero(st-1)>=v)
			e=m-1;
			else
			s=m+1;
			
		}
		if(zero(s)-zero(st-1)<v)
		return s+1;
		return s;
	}
};


int main()
{
	int t,n,*a;
	bit b(1);

	scanf("%d",&t);
	while(t--)
	{
	scanf("%d",&n);
	if(n==1)
	{printf("1\n");continue;}
	b.reset(n);
	a=(int*)calloc(n+1,sizeof(int));
	/*Position of firt element is fixed*/
	int pos=2,zc=3,nzc; //from current position (pos) we have to put the next number at (zc)th zero
	a[pos]=1;
	b.update(pos,1);

	for(int i=2;i<=n;i++)
	{
		/*If the number of elements in the bitarry is grater thean */
		if(b.zero(n)>=zc)
		{
			if(b.zero(n)-b.zero(pos-1)<zc)
			pos=b.find(1,pos,zc-(b.zero(n)-b.zero(pos-1)));
			else
			pos=b.find(pos,n,zc);
			
		}
		else
		{
			nzc=zc%b.zero(n);
			if(b.zero(n)==1)
			nzc=1;
			if(nzc==0)
			nzc=b.zero(n);

			if(b.zero(n)-b.zero(pos-1)<nzc)
			pos=b.find(1,pos,nzc-(b.zero(n)-b.zero(pos-1)));
			else
			pos=b.find(pos,n,nzc);
		}
		a[pos]=i;
		b.update(pos,1);
		zc++;
	}

	for(int i=1;i<=n;i++)
	printf("%d ",a[i]);
	printf("\n");
	
	free(a);
	
	}
}
