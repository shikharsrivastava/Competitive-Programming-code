#include<cstdio>
#include<cstdlib>
#include<cmath>
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
int* tree;	// segment tree stores the index of minimum element in the array arr which stores the time from begining required to make the next order
int* arr;
void construct(int start,int end,int index)
{
	if(start==end)
	{
	tree[index]=start;
	return;
	}	
	construct(start,(end+start-1)/2,index*2);
	construct((end+start+1)/2,end,index*2+1);
	if(arr[tree[index*2]] < arr[tree[index*2+1]])
	tree[index]=tree[index*2];
	else
	tree[index]=tree[index*2+1];

}

void upd(int start,int end,int place,int index)
{	
	if(start==end)
	return;	

	int mid=(end+start-1)/2;
	if(place<= mid)
	upd(start,mid,place,index*2);
	else
	upd(mid+1,end,place,index*2+1);
	
	if(arr[tree[index*2]] < arr[tree[index*2+1]])
	tree[index]=tree[index*2];
	else
	tree[index]=tree[index*2+1];

	return;
	

}

int main()
{
int t,p,l,size,*b,*c,ans,min_idx;
scanf("%d",&t);
while(t--)
{
scanf("%d %d",&p,&l);
arr=(int*)calloc(l+1,sizeof(int));	// stores the time taken from begining to make the next paratha
b=(int*)calloc(l+1,sizeof(int));	// stores the rank values 
c=(int*)calloc(l+1,sizeof(int));	// stores the number of parathas each chef is making
size=pow(2,ceil(log2(l))+1);
tree=(int*)calloc(size+1,sizeof(int));
for(int i=1;i<=l;i++)
{
	scanf("%d",&arr[i]);
	b[i]=arr[i];
}
construct(1,l,1);
	 ans=0;
	for(int i=1;i<=p;i++)
	{
	min_idx=tree[1];
	ans=max(ans,arr[min_idx]);	// ans is the maximum time taken from the begining
	c[min_idx]++;
	arr[min_idx]+=(c[min_idx]+1)*b[min_idx];	// change one value of base element of the array on which segment tree is built
	upd(1,l,min_idx,1);				// update the segment tree to take effect for the change
	}
	printf("%d\n",ans);
	free(tree);
	free(arr);
	free(b);
	free(c);
}
}
