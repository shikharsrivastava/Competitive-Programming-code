/* Make segment tree for each bit in the arary (1...n) i.e 32 segment tree and check the value to be xored for inversion of  kth bits (0..31) in given range l...r */
#include<bits/stdc++.h>
typedef long long int lli;
int n,*a;
struct node
{
	int n1;
	int lazy;
};
node **t;

void invert(int id,int l,int r,int s=1,int e=n,int i=1)
{
	if(t[id][i].lazy%2 !=0)
	{
		t[id][i].n1=(e-s+1)-t[id][i].n1;
		if(s!=e)
		{
		t[id][i*2].lazy+=1;
		t[id][i*2+1].lazy+=1;
		}
	}
	t[id][i].lazy=0;

	if(s>r || e<l)
	return;
	if(s>=l && e<=r)
	{
	t[id][i].n1=(e-s+1)-t[id][i].n1;
	if(s!=e)
	{
		t[id][i*2].lazy+=1;
		t[id][i*2+1].lazy+=1;
	}
	return;
	}

	int m=(e+s)/2;
	invert(id,l,r,s,m,i*2);
	invert(id,l,r,m+1,e,i*2+1);

	t[id][i].n1=t[id][i*2].n1+t[id][i*2+1].n1;
	return;
	
}

int qry(int id,int l,int r,int s=1,int e=n,int i=1)
{
	if(t[id][i].lazy%2 !=0)
	{
		t[id][i].n1=(e-s+1)-t[id][i].n1;
		if(s!=e)
		{
		t[id][i*2].lazy+=1;
		t[id][i*2+1].lazy+=1;
		}
	}
	t[id][i].lazy=0;
	
	if(s>r || e<l)
	return 0;
	if(s>=l && e<=r)
	return t[id][i].n1;
		
	int m=(e+s)/2;
	return qry(id,l,r,s,m,i*2) + qry(id,l,r,m+1,e,i*2+1);
}

int main()
{
	lli ans;
	int c,l,r,k,m,x;
	scanf("%d",&n);
	t=(node**)calloc(33,sizeof(node*));
	a=(int*)calloc(n+1,sizeof(int));
	for(int i=0;i<=32;i++)
	t[i]=(node*)calloc(4*n,sizeof(node));


	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);

	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=31;j++)
		{
			k=(a[i]>>j)&1;
			if(k==1)
			invert(j,i,i);
		}
	}

	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&c,&l,&r);
		if(c==1)
		{
			ans=0;
			for(int j=0;j<=31;j++)
			ans+=(lli)qry(j,l,r)*(1<<j);
			printf("%lld\n",ans);
		}
		if(c==2)
		{
		scanf("%d",&x);
		for(int j=0;j<=31;j++)
		{
		k=(x>>j)&1;
		if(k)
		invert(j,l,r);
		}
	
		}
	}
}
