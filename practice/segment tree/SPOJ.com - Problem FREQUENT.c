#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max3(a,b,c) a>b?(a>c?a:c):(b>c?b:c)
#define max2(a,b) a>b?a:b
struct node
{
int leftfreq;
int leftno;
int rightfreq;
int rightno;	
int maxfreq;
};
struct node* tree;
int *arr;
void construct(int l,int r,int index)
{
	
	if(l==r)
	{
	tree[index].leftfreq=tree[index].rightfreq=tree[index].maxfreq=1;
	tree[index].leftno=tree[index].rightno=arr[l];
	return;
	}
	int mid=(l+r-1)/2;
	construct(l,mid,index*2);
	construct(mid+1,r,index*2+1);
	tree[index].leftno=tree[index*2].leftno;
	tree[index].rightno=tree[index*2+1].rightno;

	if(arr[l]==arr[mid+1])
	tree[index].leftfreq=tree[index*2].leftfreq+tree[index*2+1].leftfreq;
	else
	tree[index].leftfreq=tree[index*2].leftfreq;

	if(arr[r]==arr[mid])
	tree[index].rightfreq=tree[index*2].rightfreq+tree[index*2+1].rightfreq;
	else
	tree[index].rightfreq=tree[index*2+1].rightfreq;


	if(arr[mid]==arr[mid+1])
	tree[index].maxfreq=max3(tree[index*2].maxfreq,tree[index*2+1].maxfreq,tree[index*2].rightfreq+tree[index*2+1].leftfreq);
	else
	tree[index].maxfreq=max2(tree[index*2].maxfreq,tree[index*2+1].maxfreq);

	return;
}


struct node querry(int l,int r,int start,int end,int index)
{
	
	if(l>end || r<start)
	{
	struct node ans;
	ans.leftfreq=ans.rightfreq=ans.maxfreq=0;
	ans.leftno=ans.rightno=1000000000;
	return ans;
	}

	if(l>=start && r<=end)
	return tree[index];

	int mid=(l+r-1)/2;
	struct node left=querry(l,mid,start,end,index*2);
	struct node right=querry(mid+1,r,start,end,index*2+1);
	
	struct node ans;

	if(left.leftno==right.leftno)
	ans.leftfreq=left.leftfreq+right.leftfreq;
	else
	ans.leftfreq=left.leftfreq;

	if(right.rightno==left.rightno)
	ans.rightfreq=left.rightfreq+right.rightfreq;
	else
	ans.rightfreq=right.rightfreq;

	if(left.rightno==right.leftno)
	ans.maxfreq=max3(left.maxfreq,right.maxfreq,left.rightfreq+right.leftfreq);
	else
	ans.maxfreq=max2(left.maxfreq,right.maxfreq);

	ans.leftno=left.leftno;
	ans.rightno=right.rightno;
	return ans;	

}

int main()
{
int n,q,i,j,k,l,r;
scanf("%d",&n);
while(n>0)
{

l=pow(2,ceil(log2(n))+1);
scanf("%d",&q);
arr=(int*)calloc(n+1,sizeof(int));
tree=(struct node*)calloc(l+1,sizeof(struct node));
for(i=1;i<=n;i++)
scanf("%d",&arr[i]);

construct(1,n,1);
for(k=1;k<=q;k++)
{
	scanf("%d %d",&l,&r);
	printf("%d\n",querry(1,n,l,r,1).maxfreq);	
}
free(arr);
free(tree);
scanf("%d",&n);
}
}
