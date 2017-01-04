#include<cstdio>
#include<cstdlib>
#include<algorithm>


using namespace std;

class kq
{
public:
int i;
int j;
int k;
int n;
};


class array
{
public:
int a;
int ind;
};

int* bit,maxValue;

bool func(const kq a,const kq b)
{
	return a.k>b.k;
}

bool func2(const array x,const array b)
{
	return x.a>b.a;
}


void update_bit(int index)
{
	while(index<=maxValue)
	{
	bit[index]+=1;
	index+=(index & -index);
	}
}

int sum(int index)
{	int ans=0;
	while(index>0)
	{
	ans+=bit[index];
	index-=index & -index;
	}
	return ans;
}

int main()
{

int n,q;
scanf("%d",&n);
array *arr=(array*)calloc(n+1,sizeof(array));
// takiing array input
for(int i=1;i<=n;i++)
{
scanf("%d",&arr[i].a);
arr[i].ind=i;
}
// making bit for querrying
bit=(int*)calloc(n+2,sizeof(int));
maxValue=n;

scanf("%d",&q);
kq* qr=(kq*)calloc(q+1,sizeof(kq));
// taking querry input
for(int l=1;l<=q;l++)
{
scanf("%d %d %d",&qr[l].i,&qr[l].j,&qr[l].k);
qr[l].n=l;
}
// answers array
int* ans=(int*)calloc(q+1,sizeof(int));
// sorting querries
sort(qr+1,qr+q+1,func);
// sorting array
sort(arr+1,arr+n+1,func2);


// calculating the answers
for(int i=1,j=1;i<=q;i++)
{
	while(arr[j].a>qr[i].k)
	{
	update_bit(arr[j].ind);
	j++;
	}
	ans[qr[i].n]=sum(qr[i].j)-sum(qr[i].i-1);

}

for(int i=1;i<=q;i++)
printf("%d\n",ans[i]);

free(bit);
free(qr);
free(arr);



}
