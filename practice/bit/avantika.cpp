//22:03
/*
	First sort all the elements in ascending order and use coordinate compression to give a value pos to all elements

	Simple question mo's algorithm to answer query 

	suppose currently n unique elements are present in the range and wehave the answer for them in ans we move in the current querry
	If we find a unique element elem while moving in the range , we have to add it in sorted oreder and update answer
	

	
	say initially we had -> a < b < c < d < e in our range and we found i while moving in the range such that c < i < d
	initial answer = 1*a + 2*b +* 3*c + 4*d + 5*e  
	now answer =   1*a + 2*b +* 3*c + 4*i + 5*d + 5*e 

	The contribution of elements before it in sorted order wil be the same , the contribution of elements after it in sorted order will increase by 1 
	new answer = old answer +(number of elements already present before i in old answer)*i + (sum of all elements after it already present in old answer) 
	
	number of elements already present before i in old answer - kth order statistics easily by bit (pb) update by 1
	sum of all elements after it already present in old answer - Easily by bit (sb) update by value of i

	The remove function is also the same
 	
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int *h,*sa,ns;
int BS;
lli sol;
struct bit
{
	lli *b;
	int n;
	bit()
	{
		n=1;
		b=(lli*)calloc(n+1,sizeof(lli));
	}
	void reset(int s)
	{
		free(b);
		n=s;
		b=(lli*)calloc(n+1,sizeof(lli));
	}
	void update(int p,int v)
	{
		while(p<=n)
		{
			b[p]+=v;
			p+=p&-p;
		}
	}
	lli sum(int p)
	{
		lli ans=0;
		while(p>0)
		{
		ans+=b[p];
		p-=p&-p;
		}
		return ans;
	}
};
bit pb,sb;

struct qr
{
	int l,r,id;
};
bool so(const qr a,const qr b)
{
	int x=a.l/BS;
	int y=b.l/BS;
	
	if(x==y)
	return a.r<b.r;
	return x<y;	
}
int getpos(int *a,int s,int e,int v)
{
	//printf("searching %d\n",v);
	int m;
	while(s<e)
	{
		m=(s+e)/2;
		if(a[m]<v)
		s=m+1;
		else if(a[m]>v)
		e=m-1;
		else
		return m;
	}
	return s;
}
void add(int elem)
{	
	int pos=getpos(sa,1,ns,elem);
	h[pos]++;
	if(h[pos] == 1)
	{
	pb.update(pos,1);
	sol+=pb.sum(pos)*elem+sb.sum(ns)-sb.sum(pos);
	sb.update(pos,elem);
	}
	
}
void remove(int elem)
{
	int pos=getpos(sa,1,ns,elem);
	h[pos]--;
	if(h[pos] == 0)
	{
	sol-=pb.sum(pos)*elem+sb.sum(ns)-sb.sum(pos);
	pb.update(pos,-1);
	sb.update(pos,-elem);		
	}
	
}

int main()
{
	int t,n,*a,*aa,m,x,y;
	qr *q;
	lli *ans;
	scanf("%d",&t);
	while(t--)
	{
	scanf("%d",&n);
	a=(int*)calloc(n+1,sizeof(int));
	aa=(int*)calloc(n+1,sizeof(int));
	sa=(int*)calloc(n+1,sizeof(int));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		aa[i]=a[i];	
	}

	sort(aa+1,aa+n+1);
	ns=0;
	int i=1;
	while(i<=n)
	{
		x=aa[i];
		++ns;	
		while(i<=n && x==aa[i])
		sa[ns]=aa[i],i+=1;		
	}
	/*for(int i=1;i<=ns;i++)
	printf("%d ",sa[i]);
	printf("\n");*/
	h=(int*)calloc(ns+1,sizeof(int));
	pb.reset(ns);
	sb.reset(ns);

	scanf("%d",&m);
	q=(qr*)calloc(m+1,sizeof(qr));
	ans=(lli*)calloc(m+1,sizeof(lli));

	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&q[i].l,&q[i].r);
		q[i].id=i;	
	}
	BS=sqrt(n);
	sort(q+1,q+m+1,so);	
	sol=0;
	x=1,y=0;
	int l,r;
	for(int i=1;i<=m;i++)
	{
	l=q[i].l;
	r=q[i].r;
	
	while(y>r)
	{
		remove(a[y]);
		y--;
	}
	while(y<r)
	{
		//printf("adding %d\n",a[y+1]);	
		y++;
		add(a[y]);
	}
	while(x<l)
	{
		//printf("removing %d\n",a[x]);		
		remove(a[x]);
		x++;
	}
	while(x>l)
	{
		x--;
		//printf("adding %d\n",a[x]);	
		add(a[x]);
	}	
	
	ans[q[i].id]=sol;
	}
	for(int i=1;i<=m;i++)
	printf("%lld\n",ans[i]);
	
	free(a);
	free(ans);
	free(q);
	free(aa);
	free(sa);
	free(h);
	}
	return 0;	
}

	
