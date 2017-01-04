#include<bits/stdc++.h>
/*This problem is done by mo's algorithm*/
using namespace std;
int bs;
int* cnt;
int ans;
class query
{ 
	public:
	int l;
	int r;
	int index;
};

bool cmp(const query a, const query b)
{
	int s=a.l/bs;
	int e=b.l/bs;

	if(s==e)
	return a.r<b.r;
	return s<e;
}

void add(int x)
{
	if(cnt[x]==x)
	ans--;
	else if(cnt[x]==x-1)
	ans++;

	cnt[x]++;	
	
}

void del(int x)
{
	if(cnt[x]==x)
	ans--;
	else if(cnt[x]==x+1)
	ans++;
	cnt[x]--;
}

int main()
{
int n,m,*a;

query *q;
scanf("%d %d",&n,&m);


bs=sqrt(n);
a=(int*)calloc(n+1,sizeof(int));
cnt=(int*)calloc(n+1,sizeof(int));
int* an=(int*)calloc(m+1,sizeof(int));


q=(query*)calloc(m+1,sizeof(query));
for(int i=0;i<n;i++)
scanf("%d",&a[i]);

for(int i=0;i<m;i++)
{
scanf("%d %d",&q[i].l,&q[i].r);
q[i].index=i;
q[i].l--;
q[i].r--;
}



sort(q,q+m,cmp);

ans=0;
int l=0,r=-1;
for(int i=0;i<m;i++)
{
	int left=q[i].l;
	int right=q[i].r;

	while(r<right)
	{
		r++;
		if(a[r]<n+1)
		add(a[r]);
	}
	
	while(r>right)
	{
	if(a[r]<n+1)
	del(a[r]);
	r--;
	}

	while(l<left)
	{
		if(a[l]<n+1)
		del(a[l]);
		l++;
	}

	while(l>left)
	{
		l--;
		if(a[l]<n+1)
		add(a[l]);
		
	}

	an[q[i].index]=ans;
}
for(int i=0;i<m;i++)
printf("%d\n",an[i]);
free(a);
free(an);
free(cnt);
free(q);

return 0;
}
