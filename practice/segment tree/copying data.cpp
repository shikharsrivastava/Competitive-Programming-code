/*Mapping indices of array x with array a by building segment tree on x and passing indices to be mapped as AP(arithmatic progression) using segment tree
 with lazy propogation and overwriting the existing values.For query , querying using segment tree , if the index is unchange throughout i.e. value is 0
 Fetching from array b otherwise fetching from array a at the index returned by segment tree (the index after latest update)*/
#include<bits/stdc++.h>
struct node
{
	int v;
	int a;
	int l;
};
node *t;
int n,*a,*b;

void update(int x,int l,int r,int s=1,int e=n,int i=1)
{
	int m=(e+s)/2;
	if(t[i].l>0)
	{
		t[i].v=t[i].l;
		if(s!=e)
		{
			t[i*2].l=t[i].l;	
			t[i*2+1].l=t[i].l+(m-s+1);
		}
		t[i].l=0;
	}
 

	if(s>r || e<l)
	return;
	
	if(s>=l && e<=r)
	{
		int a=x+(s-l);
		t[i].v=a;
		if(s!=e)
		{
		t[i*2].l=a;
		t[i*2+1].l=a+(m-s+1);
		}
	return;
	}
	update(x,l,r,s,m,i*2);
	update(x,l,r,m+1,e,i*2+1);
	return;

}

int get(int id,int s=1,int e=n,int i=1)
{
	int m=(s+e)/2;
	if(t[i].l>0)
	{
		t[i].v=t[i].l;
		if(s!=e)
		{
			t[i*2].l=t[i].l;	
			t[i*2+1].l=t[i].l+(m-s+1);
		}
		t[i].l=0;
	}
 

	if(s==e)
	return t[i].v;
	
	if(id<=m)
	return get(id,s,m,i*2);
	else
	return get(id,m+1,e,i*2+1);
	
}

int main()
{
	int m,tp,x,y,k,f;
	scanf("%d %d",&n,&m);
	a=(int*)calloc(n+1,sizeof(int));
	b=(int*)calloc(n+1,sizeof(int));
	t=(node*)calloc(4*n,sizeof(node));
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	
	for(int i=1;i<=n;i++)
	scanf("%d",&b[i]);

	for(int i=1;i<=m;i++)
	{
	scanf("%d",&tp);
	if(tp==1)
	{
		scanf("%d %d %d",&x,&y,&k);
		update(x,y,y+k-1);
	}
	else
	{
		scanf("%d",&x);
		f=get(x);
		if(f==0)
		printf("%d\n",b[x]);
		else
		printf("%d\n",a[f]);	
	}
	}
	free(a);
	free(b);	
	free(t);
	
}
