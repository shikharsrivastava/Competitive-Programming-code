#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pb push_back
#define mp make_pair

struct node
{
	bool shelf[1001];
	int sum;
	int l,r;
} st[1091000];

int id = 0;
int N,M;
int q1(int pos,int shno,int prev,int l=1,int r=N)
{

	int idx = id++;
	st[idx].l = st[prev].l;
	st[idx].r = st[prev].r;
	st[idx].sum = st[prev].sum;
	for(int i=1;i<=M;i++)
		st[idx].shelf[i] = st[prev].shelf[i];

	if(l == r)
	{
		if(!st[idx].shelf[shno])
		st[idx].shelf[shno] = true,st[idx].sum += 1;
		return idx;
	}	
	int m = (l+r)>>1;
	if(pos <= m)
		st[idx].l = q1(pos,shno,st[prev].l,l,m);
	else
	 	st[idx].r = q1(pos,shno,st[prev].r,m+1,r);

	st[idx].sum = st[st[idx].l].sum + st[st[idx].r].sum;
	return idx;	
}

int q2(int pos,int shno,int prev,int l=1,int r=N)
{

	int idx = id++;
	st[idx].l = st[prev].l;
	st[idx].r = st[prev].r;
	st[idx].sum = st[prev].sum;
	for(int i=1;i<=M;i++)
		st[idx].shelf[i] = st[prev].shelf[i];

	if(l == r)
	{
		if(st[idx].shelf[shno])
		{st[idx].shelf[shno] = false;st[idx].sum -= 1;}
		return idx;
	}	
	int m = (l+r)>>1;
	if(pos <= m)
		st[idx].l = q2(pos,shno,st[prev].l,l,m);
	else
	 	st[idx].r = q2(pos,shno,st[prev].r,m+1,r);

	st[idx].sum = st[st[idx].l].sum + st[st[idx].r].sum;	
	return idx;	
}

int q3(int pos,int prev,int l=1,int r=N)
{
	
	if(r<l)
		exit(0);
	int idx = id++;
	
	st[idx].l = st[prev].l;
		
	st[idx].r = st[prev].r;
	st[idx].sum = st[prev].sum;
	for(int i=1;i<=M;i++)
		st[idx].shelf[i] = st[prev].shelf[i];
		
	if(l == r)
	{
		for(int i=1;i<=M;i++)
		{
			if(st[idx].shelf[i])
				st[idx].shelf[i] = false , st[idx].sum--;
			else
				st[idx].shelf[i] = true , st[idx].sum++;
		}
		return idx;
	}	
	int m = (l+r)>>1;
	if(pos <= m)
		st[idx].l = q3(pos,st[prev].l,l,m);
	else
	 	st[idx].r = q3(pos,st[prev].r,m+1,r);

	st[idx].sum = st[st[idx].l].sum + st[st[idx].r].sum;
	return idx;	
}

int build(int l = 1,int r = N)
{
	int idx = id++;
	st[idx].sum = 0;
	if(l == r)
		return idx;
	int m = (l+r)>>1;
	st[idx].l = build(l,m);
	st[idx].r = build(m+1,r);
	return idx;
}

int root[100005];
int op[100005];
int main()
{
	int q;
	scanf("%d %d %d",&N,&M,&q);
	root[0] = build();
	int c,i,j,k=0,ind = 0;
	op[0] = 0;
	while(q--)
	{
		scanf("%d",&c);
		if(c == 1)
		{
			scanf("%d %d",&i,&j);
			root[++k] = q1(i,j,root[op[ind]]);
			printf("%d\n",st[root[k]].sum);
			op[++ind] = k;
		}
		else if(c == 2)
		{
			scanf("%d %d",&i,&j);
			root[++k] = q2(i,j,root[op[ind]]);
			printf("%d\n",st[root[k]].sum);
			op[++ind] = k;
		}
		else if(c == 3)
		{
			//printf("In %d , k =%d , ind = %d , op[%d] = %d ,root = %d , N = %d\n",3,k,ind,ind,op[ind],root[op[ind]],N);
			scanf("%d",&i);
			root[++k] = q3(i,root[op[ind]]);
			printf("%d\n",st[root[k]].sum);
			op[++ind] = k;
		}
		else if(c == 4)
		{
			scanf("%d",&i);
			int oid = op[i];
			printf("%d\n",st[root[oid]].sum);
			op[++ind] = oid;
		}

	}
	return 0;
}
