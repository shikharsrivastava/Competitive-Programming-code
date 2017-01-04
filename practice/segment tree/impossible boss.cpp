//18:38
#include<bits/stdc++.h>
typedef long long int lli;
struct node
{
	lli sum;
	lli a;
	lli d;
};
node* tree;
int n;

void update(int l,int r,int s=1,int e=n,int i=1)
{
	int mid=(e+s)/2,num;
	if(tree[i].a>0)
	{	
		num=e-s+1;
		tree[i].sum+=(2*tree[i].a+(num-1)*tree[i].d)*(num)/2;
		if(s!=e)
		{
		tree[i*2].a+=tree[i].a;
		tree[i*2].d+=tree[i].d;
		tree[i*2+1].a+=tree[i].a+(mid-s+1)*tree[i].d;
		tree[i*2+1].d+=tree[i].d;		
		}
		tree[i].a=tree[i].d=0;
	}


	if(s>r || e<l)
	return;

	if(s>=l && e<=r)
	{
		tree[i].sum+=(2*(s-l+1)+(e-s))*(lli)(e-s+1)/2;
		if(s!=e)
		{
			tree[i*2].a+=(s-l+1);
			tree[i*2].d+=1;
			tree[i*2+1].a+=(mid-l+2);
			tree[i*2+1].d+=1;
		}	
		return;
	}
	update(l,r,s,mid,i*2);
	update(l,r,mid+1,e,i*2+1);
	tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
	return;	
}


lli sum(int l,int r,int s=1,int e=n,int i=1)
{
	int mid=(e+s)/2,num;
	if(tree[i].a>0)
	{	
		num=e-s+1;
		tree[i].sum+=(2*tree[i].a+(num-1)*tree[i].d)*num/2;
		if(s!=e)
		{
		tree[i*2].a+=tree[i].a;
		tree[i*2].d+=tree[i].d;
		tree[i*2+1].a+=tree[i].a+(mid-s+1)*tree[i].d;
		tree[i*2+1].d+=tree[i].d;		
		}
		tree[i].a=tree[i].d=0;
	}

	if(s>r || e<l)
	return 0;
	
	if(s>=l && e<=r)
	return tree[i].sum;
	
	return sum(l,r,s,mid,i*2)+sum(l,r,mid+1,e,i*2+1);
}

int main()
{
	int q,l,r,c;
	scanf("%d %d",&n,&q);
	tree=(node*)calloc(4*n,sizeof(node));
	while(q--)
	{
	scanf("%d %d %d",&c,&l,&r);
	if(c==0)
	update(l,r);
	else
	printf("%lld\n",sum(l,r));
	}

	free(tree);
}

