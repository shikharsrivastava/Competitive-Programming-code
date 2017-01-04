#include<cstdio>
#include<cstdlib>

using namespace std;
int mergesort(int*,int,int);
int merge(int*,int,int,int);	
int *fact,*inv_count,n;
long long total_inversion;
int main()
{
int ans,t,k,rank,parityp,parityq;
fact=(int*)calloc(100001,sizeof(int));

fact[0]=1;
// storing factorial
for(int i=1;i<=100000;i++)
fact[i]=((long long)fact[i-1]*i)%1000000007;

scanf("%d",&t);
while(t--)
{
total_inversion=rank=0;
scanf("%d %d",&n,&k);

int *p,*q,*q2;
inv_count=(int*)calloc(100001,sizeof(int));
p=(int*)calloc(n+1,sizeof(int));
q=(int*)calloc(n+1,sizeof(int));
q2=(int*)calloc(n+1,sizeof(int));

for(int i=0;i<n;i++)
scanf("%d",&p[i]);

for(int i=0;i<n;i++)
{
scanf("%d",&q[i]);
q2[i]=q[i];
}

if(k==n)
{
int i;
for(i=0;i<n;i++)
	if(q[0]==p[i])
		break;
int flag=0;
for(int j=0,k=i;j<n;j++,k++)
{	
	if(k==n)
	k=0;
	
	if(q[j]!=p[k])
	{
	flag=1;
	printf("-1\n");
	break;
	}
}
if(flag==0)
printf("%d\n",q[0]);
}

else if(k%2==0)
{
mergesort(q2,0,n-1);
parityq=total_inversion%2;
for(int i=0;i<n;i++)
rank=(rank+((long long)inv_count[q[i]]*fact[n-i-1])%1000000007)%1000000007;
rank=(rank+1)%1000000007;
printf("%d\n",rank);
}
else
{
mergesort(p,0,n-1);
parityp=total_inversion%2;


total_inversion=0;
free(inv_count);
inv_count=(int*)calloc(100001,sizeof(int));

mergesort(q2,0,n-1);
parityq=total_inversion%2;


if(parityp==parityq)
{
if(q[n-2]<q[n-1])
{
// 1 indexed rank is odd
for(int i=0;i<n;i++)
rank=(rank+((long long)inv_count[q[i]]*fact[n-i-1]))%1000000007;
rank=(rank+2)%1000000007;
rank=((long long int)rank*500000004)%1000000007;
printf("%d\n",rank);
}
else
{
// 1 indexed rank is even
for(int i=0;i<n;i++)
rank=(rank+((long long)inv_count[q[i]]*fact[n-i-1]))%1000000007;
rank=(rank+1)%1000000007;
rank=((long long int)rank*500000004)%1000000007;
printf("%d\n",rank);
}
}
else
{
printf("-1\n");
}
}

free(p);
free(q);
free(q2);
free(inv_count);
}
}

int mergesort(int *q,int start,int end)
{
if(start<end)
{
int mid=(start+end)/2;
mergesort(q,start,mid);
mergesort(q,mid+1,end);
merge(q,start,mid,end);
}
}

int merge(int* q,int start,int mid,int end)
{

int aelem=mid-start+1;
int belem=end-mid;
int a[aelem];
int b[belem];
for(int i=0;i<aelem;i++)
a[i]=q[start+i];

for(int i=0;i<belem;i++)
b[i]=q[mid+1+i];

int i=0,j=0,k=start;
int count=0;
while(i<aelem && j<belem)
{

	if(a[i]<b[j])
	{
	q[k]=a[i];
	inv_count[a[i]]+=count;
	i++;
	}
	else
	{
	q[k]=b[j];
	j++;
	count++;
	total_inversion+=(aelem-i);
	}
	k++;
}

while (i < aelem)
    {
        q[k] = a[i];
	inv_count[a[i]]+=count;
        i++;
        k++;
    }
 
    while (j < belem)
    {
        q[k] = b[j];
        j++;
        k++;
    }


}
