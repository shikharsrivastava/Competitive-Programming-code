#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct node
{
	lli mx;	
	lli lazy;
} *st;
struct point
{
	int x;
	int y;
	int c;
} p[100005];
int n;

void dolazy(int s,int e,int id)
{
	st[id].mx += st[id].lazy;
	if(s!=e)
	st[id*2].lazy += st[id].lazy , st[id*2+1].lazy += st[id].lazy;
	st[id].lazy = 0;
}

void setlazy(int s,int e,lli v,int id)
{
	if(s!=e)
		st[id*2].lazy += v , st[id*2+1].lazy += v;
	
}
bool comp(const point &a, const point &b)
{
	if(a.x == b.x)
	return a.y < b.y;
	return a.x<b.x;
}

void update(int l,int r,int v,int s=0,int e=100000,int id =1)
{
	if(st[id].lazy != 0)
	dolazy(s,e,id);
	
	if(s>r || e<l)
	return;
	else if(s >=l && e<=r)
	{
		st[id].mx += v;
		setlazy(s,e,v,id);
	}
	else
	{
		int m = (s+e)>>1;
		update(l,r,v,s,m,id*2);
		update(l,r,v,m+1,e,id*2+1);
		st[id].mx= max(st[id*2].mx,st[id*2+1].mx);
	}
}


lli func(int l)
{
	int x,y,c,s;
	if(l == 0)
	return 0;
	st = (node*)calloc(400005,sizeof(node));
	int enx = 1,stx = 0,stptr = 1;
	lli ans = 0;
	int limit  = 100001;
	while(stx <= limit)
	{
		// moving ending line
		while(enx<=n && p[enx].x <= stx+l-1)
		{
			
			y = p[enx].y;
			c = p[enx].c;
			s = max(0,y-l+1);
			update(s,y,c);
			enx++;
		}
		ans = max(ans,st[1].mx);
		// moving starting line
		stx++;
		while(stptr <= n && p[stptr].x <stx)
		{
			y = p[stptr].y;
			c = p[stptr].c;
			s = max(0,y-l+1);
			update(s,y,-c);
			stptr++;
		}
	}
	free(st);
	return ans;
}


int main()
{
	int l;
	scanf("%d %d",&n,&l);
	for(int i=1;i<=n;i++)
	scanf("%d %d %d",&p[i].x,&p[i].y,&p[i].c);
	
	sort(p+1,p+n+1,comp);	
	
	lli maxval = func(l);
	int s = 1 , e = l;
	while(s<e)
	{
		int m = (s+e)>>1;
		if(func(m) >= maxval)
		e = m;
		else
		s = m+1;	
	}
	printf("%lld %d\n",maxval,s);
}

