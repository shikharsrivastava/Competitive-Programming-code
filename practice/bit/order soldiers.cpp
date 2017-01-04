//23:08
#include<bits/stdc++.h>
using namespace std;

int *t,n;

void construct(int l=1,int r=n,int id=1)
{
	if(l==r)
	{t[id]=1;return;}
	
	construct(l,(l+r)/2,id*2);
	construct((l+r)/2+1,r,id*2+1);
	
	t[id]=t[id*2]+t[id*2+1];
	return;
}
void update(int p,int l=1,int r=n,int id=1)
{
	t[id]--;
	if(l==r)
	return;
	int m=(l+r)/2;
	
	if(p<=m)
	update(p,l,m,id*2);
	else
	update(p,m+1,r,id*2+1);
}

int get(int L,int R,int l=1,int r=n,int id=1)
{
	
	if(l>R || r<L)
	return 0;
	
	if(l>=L && r<=R)
	return t[id];
	
	int m=(l+r)/2;
	return get(L,R,l,m,id*2)+get(L,R,m+1,r,id*2+1);
	
}

int find(int v)
{
int s=1,e=n,m;
	while(s<e)
	{
		m=(s+e)/2;
		if(get(1,m)>=v)
		e=m-1;
		else
		s=m+1;
	}
	if(get(1,s)<v)
	return s+1;
	else
	return s;
	
}
int main()
{
	int tc,*a,*ans;
	scanf("%d",&tc);
	while(tc--)
	{
	scanf("%d",&n);
	t=(int*)calloc(4*n,sizeof(int));
	a=(int*)calloc(n+1,sizeof(int));
	ans=(int*)calloc(n+1,sizeof(int));
	construct();
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);

	for(int i=n,j=0;i>0;i--,j++)
	{
		ans[i]=find(n-j-(a[i]+1)+1);
		update(ans[i]);
	}
	
	for(int i=1;i<=n;i++)
	printf("%d ",ans[i]);	
	printf("\n");
	
	free(t);
	free(a);
	free(ans);	
	}

}

