//2:03
#include<bits/stdc++.h>
using namespace std;
struct flight
{
	int st;
	int d;
	int et;
	int m;
};

bool so(const flight a,const flight b)
{
	if(a.et==b.et)
	return a.st<b.st;
	return a.et<b.et;
}


int findlower(int *a,int s,int e,int v)
{
	int m;
	while(s<e)
	{
		m=(s+e)/2;
		if(a[m]<v)
		s=m+1;
		else
		e=m-1;
	}
	if(a[s]>v)
	return s-1;
	return s;
}
int main()
{
	int n,t,*ep,*ansep,id,idx,ans;
	flight *a;
	scanf("%d",&t);
	while(t--)
	{	
	scanf("%d",&n);
	
	ep=(int*)calloc(n+1,sizeof(int));
	ansep=(int*)calloc(n+1,sizeof(int));
	a=(flight*)calloc(n+1,sizeof(flight));
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&a[i].st,&a[i].d,&a[i].m);
		a[i].et=a[i].st+a[i].d;
		ep[i]=a[i].et;	
	}
	
	sort(a+1,a+n+1,so);
	sort(ep+1,ep+n+1);
	printf("Sorted\n");
	for(int i=1;i<=n;i++)
		printf("st = %d  et = %d\n",a[i].st,a[i].et);
	
	int id,idx,ans=0;
	for(int i=1;i<=n;i++)
	{
		printf("i = %d , st =%d, et = %d\n",i,a[i].st,a[i].et);
		idx=findlower(ep,1,n,a[i].et);
		id=findlower(ep,1,n,a[i].st);
		printf("idx = %d , id = %d\n",idx,id);
		ansep[i]=max(a[i].m+ansep[id],ansep[idx]);
	}
	for(int i=1;i<=n;i++)
	printf("%d ",ansep[i]);
	printf("\n");
	printf("%d\n",ansep[n]);
	free(a);
	free(ep);
	free(ansep);
	}
}
