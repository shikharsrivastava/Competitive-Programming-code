//28
#include<bits/stdc++.h>
#define max(a,b) a>b?a:b
typedef long long int ll;
struct node
{
	ll sum;
	int max;
};

node *t;
int n,*a;

void cons(int s=1,int e=n,int i=1)
{
	if(s==e)
	{
	t[i].sum=a[s];
	t[i].max=a[s];
	return;
	}
	int m=(e+s)/2;
	cons(s,m,i*2);
	cons(m+1,e,i*2+1);
	
	t[i].sum=(t[i*2].sum+t[i*2+1].sum);
	t[i].max=max(t[i*2].max,t[i*2+1].max);
	return;
}

void dorealmod(int s,int e,int x,int i)
{
	if(s==e)
	{
	t[i].sum%=x;
	t[i].max%=x;
	return;
	}
	if(t[i*2].max>=x)
	dorealmod(s,(s+e)/2,x,i*2);
	if(t[i*2+1].max>=x)
	dorealmod((s+e)/2+1,e,x,i*2+1);
	
	t[i].max=max(t[i*2].max,t[i*2+1].max);
	t[i].sum=t[i*2].sum+t[i*2+1].sum;
	return;
}

void mod(int l,int r,int x,int s=1,int e=n,int i=1)
{

	if(s>r || e<l)
	return;

	if(s>=l && e<=r)
	{
		if(t[i].max>=x)
		dorealmod(s,e,x,i);
		return;	
	}
	int m=(e+s)/2;
	mod(l,r,x,s,m,i*2);
	mod(l,r,x,m+1,e,i*2+1);

	t[i].sum=t[i*2].sum+t[i*2+1].sum;
	t[i].max=max(t[i*2].max,t[i*2+1].max);
	return;
}



void modify(int k,int x,int s=1,int e=n,int i=1)
{
	if(s==e)
	{
		t[i].max=x;
		t[i].sum=x;
		return;
	}

	int m=(e+s)/2;
	if(k<=m)
	modify(k,x,s,m,i*2);
	else
	modify(k,x,m+1,e,i*2+1);
	
	t[i].max=max(t[i*2].max,t[i*2+1].max);
	t[i].sum=t[i*2].sum+t[i*2+1].sum;
	return;
}

ll summ(int l,int r,int s=1,int e=n,int i=1)
{
	if(s>r || e<l)
	return 0;
	
	if(s>=l && e<=r)
	return t[i].sum;
	
	int m=(e+s)/2;
	return summ(l,r,s,m,i*2)+summ(l,r,m+1,e,i*2+1);
}


int main()
{
	
	int m,type,l,r,x,k;

	scanf("%d %d",&n,&m);
	a=(int*)calloc(n+1,sizeof(int));
	t=(node*)calloc(4*n,sizeof(node));
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	cons();
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&type);
		if(type==1)
		{
			scanf("%d %d",&l,&r);
			printf("%lld\n",summ(l,r));
		}
		else if(type==2)
		{
		scanf("%d %d %d",&l,&r,&x);
		mod(l,r,x);
		}
		else
		{
			scanf("%d %d",&k,&x);
			modify(k,x);
		}

	}

	
}
