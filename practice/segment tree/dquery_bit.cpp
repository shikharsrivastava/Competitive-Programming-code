#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

/*
	We make a bit array that stores 1 at first occurence of each element. We then buid up  a binary indexed tree on this bit array.
	The sum from 1 to r will give the nimber of distinct elements in the range[1,r].We process the querries offline by sorting them in increasing order of their
	starting points.Initially start=1 , we move to the starting point of a querry in steps of 1 , and mark the next occurence of the element just released 
	(a[start]) as 1 nad increase the value of start.If there is no next occurence of the element in array we leave it.We kwwp doing this until we reach the 
	starting point of the query by step by step increasing start.On reaching there we get the answer by sum(1,endpoint_of-query)-sum(1,startpoint-1).
	We use binary search in sorted sequence to get the next occurence of the element in the array.
*/

class query
{
	public:
	int i;
	int j;
	int index;
};
class array
{
	public:
	int num;
	int index;
};

int *bit,n,*bitarray,*answer;
query *q;
array *a,*b;

bool st(const query a, const query b)
{	
	if(a.i==b.i)
	return a.j<b.j;
	return a.i<b.i;
}

bool so(const array a, const array b)
{
	if(a.num==b.num)
	return a.index<b.index;
	return a.num<b.num;
}

void update(int pos,int val)
{
	while(pos<=n)
	{
	bit[pos]+=val;
	pos+=(pos&-pos);
	}
}

int sum(int pos)
{
	int ans=0;
	while(pos>0)
	{
	ans+=bit[pos];
	pos-=pos & -pos;
	}
	return ans;
}

int find(int num,int occ_no)
{
	int start=1,end=n,mid;
	while(start<end)
	{
		mid=(end+start-1)/2;
		if(num<b[mid].num)
		end=mid-1;
		else if(num >b[mid].num)
		start=mid+1;
		else
		{
		start=mid;
		break;
		}
	}
	while(b[start].index>occ_no)
	start--;	
	while(b[start].index<=occ_no)
	start++;
	if(b[start].num==num)
	return b[start].index;
	return -1;
	
}


int main()
{
	int *cum,nq,pos;
	scanf("%d",&n);
	a=(array*)calloc(n+1,sizeof(array));
	b=(array*)calloc(n+1,sizeof(array));
	bitarray=(int*)calloc(n+1,sizeof(int));
	cum=(int*)calloc(n+1,sizeof(int));
	bit=(int*)calloc(n+1,sizeof(int));
	for(int i=1;i<=n;i++)
	{
	scanf("%d",&a[i].num);
	b[i].num=a[i].num;
	a[i].index=b[i].index=i;	
	}	
	scanf("%d",&nq);
	q=(query*)calloc(nq+1,sizeof(query));
	answer=(int*)calloc(nq+1,sizeof(int));	
	for(int i=1;i<=nq;i++)
	{
	scanf("%d %d",&q[i].i,&q[i].j);
	q[i].index=i;	
	}

	sort(q+1,q+nq+1,st);
	sort(b+1,b+n+1,so);

	for(int i=1;i<=n;i++)
	{
		if (b[i].num != b[i-1].num)
		bitarray[b[i].index]++;
	}
	for(int i=1;i<=n;i++)
	{
	cum[i]=cum[i-1]+bitarray[i];
	//printf("%d ",bitarray[i]);
	}
	
	// constructing Bit
	for(int i=1;i<=n;i++)
	bit[i]=cum[i]-cum[i-(i& -i)];
	
	int start=1;
	for(int i=1;i<=nq;i++)
	{
		while(start<q[i].i)
		{
			
			pos=find(a[start].num,start);
			if(pos>0)
			{
			update(pos,+1);		
			}
			start++;
		}
		answer[q[i].index]=sum(q[i].j)-sum(start-1);
	}
	
	printf("\n");
	for(int i=1;i<=nq;i++)
	printf("%d\n",answer[i]);

	free(a);
	free(b);
	free(bitarray);
	free(q);
	free(bit);
	free(answer);
	free(cum);
		

}
