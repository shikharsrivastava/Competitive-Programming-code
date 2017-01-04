/*
	Let us note that we can use binary search to find answer to the one query. Suppose at some moment was fixed height h and need to know will fit the rectangle with width w and height h to the segment of fence from l-th to r-th panel. Let us build data structure that can answer to this question. This will be persistent segment tree with unusual function inside: maximum number of consecutive ones in segment (maxOnes). In leaves of segment tree will be only numbers 0 and 1. To calculate this function need to know some other values, specifically:

len — length of the segment in vertex of segment tree, prefOnes — length of prefix that consists only of ones, sufOnes — length of the suffix consist only of ones.

These functions are computed as follows:

maxOnes is equal to max(maxOnes(Left), maxOnes(Right), sufOnes(Left) + prefOnes(Right));

prefOnes equals prefOnes(Right) + len(Left) in case of len(Left) = prefOnes(Left), and prefOnes(Left) otherwise;

sufOnes equals sufOnes(Left) + len(Right) in case of len(Right) = sufOnes(Right), and sufOnes(Right) otherwise;

len = len(left) + len(Right);

Left и Right — it is left and right sons of vertex in segment tree.

As mentioned above, tree must be persistent, and it must be built as follows. First, builded empty tree of zeros. Next in position of highest plank need to put 1. The same doing for planks in decreasing order. For example if fence described with sequence [2, 5, 5, 1, 3] then bottom of segment tree will changed as follows:

[0, 0, 0, 0, 0] -> [0, 1, 0, 0, 0] -> [0, 1, 1, 0, 0] -> [0, 1, 1, 0, 1] -> [1, 1, 1, 0, 1] -> [1, 1, 1, 1, 1].

And we need to remember for all hi their version of tree. Now to answer the question we need to make query in our segment tree (that corresponding to height h) on segment [l, r]. If maxOnes form this query less than w, then rectangle impossible to put (otherwise possible).

Building of tree will take O(nlogn) time and memory. Time complexity to the one query will take O(log2n) time.

*/
#include<bits/stdc++.h>
#define max3(a,b,c) a>b?(a>c?a:c):(b>c?b:c)
#define max2(a,b) a>b?a:b
using namespace std;
struct node
{
	int max;
	int len;
	int lmax;
	int rmax;
	int l;
	int r;
} *t;

struct s
{
	int num;
	int ind;
} *sa;

int nxt,n,*root;

bool so(const s a, const s b)
{
	if(a.num==b.num)
	return a.ind>b.ind;
	return a.num>b.num;
	
}
void cons(int s=1,int e=n,int id=1)
{
	t[id].len=(e-s+1);
	if(s==e)
	return;
	t[id].l=++nxt;
	t[id].r=++nxt;	
	int m=(e+s)/2;
	cons(s,m,t[id].l);
	cons(m+1,e,t[id].r);
	return;
	
}

int update(int pos,int prev,int s=1,int e=n)
{
	int id=++nxt;
	if(s==e)
	{
	t[id].lmax=t[id].rmax=t[id].max=t[id].len=1;
	return id;
	}
	t[id].l=t[prev].l;
	t[id].r=t[prev].r;
	
	int mid=(e+s)/2;
	if(pos<=mid)
	t[id].l=update(pos,t[prev].l,s,mid);
	else
	t[id].r=update(pos,t[prev].r,mid+1,e);

	int lchild=t[id].l;
	int rchild=t[id].r;
	t[id].max=max3(t[lchild].max,t[rchild].max,t[lchild].rmax+t[rchild].lmax);
	t[id].len=t[lchild].len+t[rchild].len;

	if(t[lchild].lmax==t[lchild].len)
	t[id].lmax=t[lchild].len+t[rchild].lmax;
	else
	t[id].lmax=t[lchild].lmax;

	if(t[rchild].rmax==t[rchild].len)
	t[id].rmax=t[rchild].len+t[lchild].rmax;
	else
	t[id].rmax=t[rchild].rmax;

	return id;
} 

node query(int id,int l,int r,int s=1,int e=n)
{
	node ans;
	
	if(s>r || e<l)
	{
	ans.lmax=ans.rmax=ans.len=ans.max=0;
	return ans;
	}
	if(s>=l && e<=r)
	return t[id];
	
	int mid=(e+s)/2;
	node left=query(t[id].l,l,r,s,mid);
	node right=query(t[id].r,l,r,mid+1,e);

	ans.len=left.len+right.len;
	ans.max=max3(left.max,right.max,left.rmax+right.lmax);
	
	if(left.len==left.lmax)
	ans.lmax=left.len+right.lmax;
	else
	ans.lmax=left.lmax;

	if(right.len==right.rmax)
	ans.rmax=right.len+left.rmax;
	else
	ans.rmax=right.rmax;
	
	return ans;
	
}

int find(int l,int r,int w)
{
	int s=1,e=n,m,ones;
	while(s<e)
	{
		m=(e+s)/2;
		ones=query(root[m],l,r).max;
		if(ones>=w)
		e=m-1;
		else
		s=m+1;
	}
	ones=query(root[s],l,r).max;
	if(ones<w)
	return sa[s+1].num;
	else
	return sa[s].num;
}

int main()
{
	nxt=1;
	int v,l,r,m,w;
	scanf("%d",&n);
	int *a=(int*)calloc(n+1,sizeof(int));
	sa=(s*)calloc(n+10,sizeof(s));
	t=(node*)calloc(pow(2,ceil(log2(n))+1)+n*(ceil(log2(n))+1),sizeof(node));
	root=(int*)calloc(n+2,sizeof(int));
	root[0]=1;
	for(int i=1;i<=n;i++)
	{
	scanf("%d",&a[i]);
	sa[i].num=a[i];
	sa[i].ind=i;	
	}
	cons();

	sort(sa+1,sa+n+1,so);
	
	for(int i=1;i<=n;i++)
	root[i]=update(sa[i].ind,root[i-1]);

	scanf("%d",&m);
	while(m--)
	{
		scanf("%d %d %d",&l,&r,&w);
		printf("%d\n",find(l,r,w));
	}
	free(sa);
	free(t);
	free(a);
	free(root);
	
return 0;		
}
