/*

Simple question we just have to know thw maximum in a rang nd the position of maximum
First sort the dominoes for coordinate compression along by x coordinates
Then starting from the right , for each domino store the maximum domino fallen if it falls includeing itself

ans for domino i kept in ascending order of x coordinate
ans[i]=ans[j] + i -pos;
where ans[j] is the answer for the domino j in range of fall of domino i such that ans[j] is maximum of all ans[k] in range of fall of i i<=k<=range of fall of i
and pos is the position of j
*/
#include<bits/stdc++.h>
using namespace std;
struct domino
{
	int x;
	int h;
	int id;
} *d;
struct node
{
	int mx;
} *t;
bool so(const domino a,const domino b)
{
	return a.x<b.x;
}
int n;

void update(int p,int v,int s=1,int e=n,int id=1)
{
	if(s==e)
	{t[id].mx=v;return;}
	
	int m=(s+e)/2;
	if(p<=m)
	update(p,v,s,m,id*2);
	else
	update(p,v,m+1,e,id*2+1);


	t[id].mx=max(t[id*2].mx,t[id*2+1].mx);
}

int getmax(int l,int r,int s=1,int e=n,int id=1)
{
	
	int ans;
	if(s>r || e<l)
	{ans=0;return ans;}
	
	if(s>=l && e<=r)
	{ans=t[id].mx;return ans;}
	
	int m=(s+e)/2;

	int lft=getmax(l,r,s,m,id*2);
	int rgt=getmax(l,r,m+1,e,id*2+1);

	
	ans=max(lft,rgt);

	return ans;
	
}

int findlower(int v)
{
	int s=1,e=n,m;
	while(s<e)
	{
	
	m=(s+e)/2;

	if(d[m].x<=v)
	s=m+1;
	else
	e=m-1;
	}

	if(d[s].x >v)
	return s-1;
	else
	return s;
}


int main()
{
	int pos;
	scanf("%d",&n);
	d=(domino*)calloc(n+1,sizeof(domino));
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&d[i].x,&d[i].h);
		d[i].id=i;
	}
	sort(d+1,d+n+1,so);
	
	int limit;
	t=(node*)calloc(n*4,sizeof(node));
	int *ans=(int*)calloc(n+1,sizeof(int));
	int tmp;
	update(n,n);
	for(int i=n;i>0;i--)
	{
		limit=findlower(d[i].x+d[i].h-1);
		tmp=getmax(i,limit);
		tmp=max(tmp,i);
		//printf("For i = %d  x = %d , limit = %d , max = %d\n",i,d[i].x,limit,tmp);
		ans[d[i].id]=tmp-i+1;
		update(i,max(limit,tmp));
	}
	for(int i=1;i<=n;i++)
	printf("%d ",ans[i]);
	printf("\n");
}
