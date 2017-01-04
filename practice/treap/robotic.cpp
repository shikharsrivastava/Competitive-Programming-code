//11:25
#include<bits/stdc++.h>
#define cnt(t) (t ? t->count : 0)
#define updatecnt(t) (t ? (t->count = cnt(t->l) + cnt(t->r) + 1) : 0)
#define mn(t) (t ? t->mini : 1000000000)
#define ps(t) (t ? t->pos : 0)
#define reverse(t) (t ? (t->rev ^=true) : 0)
#define ind(t) (t ? t->id : 0)
#define index(t) (t ? t->idx : 0)
using namespace std;
typedef struct node * pnode;
struct node
{
	int v;
	int id,idx;
	int p;
	bool rev;
	int count;
	int mini;
	int pos;
	pnode l,r;
} *treap = NULL;

void push(pnode t)
{
	if(t && t->rev)
	{	
		t->pos = cnt(t)- t->pos +1;
		t->rev ^= true;
		swap(t->l,t->r);
		if(t->l) t->l->rev ^=true;
		if(t->r) t->r->rev ^=true;
	}
}

void updatemin(pnode t,int f = false)
{
	if(t)
	{

		push(t->l);
		push(t->r);
		int m = mn(t->l);
		int pos = ps(t->l);
		int id = ind(t->l);
		if(t->v <= m)
		{
			if(t->v == m)
			pos = index(t) < id ? (cnt(t->l)+1) : pos , id  = min(id,index(t)); 
			else
			m = t->v , pos = cnt(t->l) + 1,id = index(t);
		}
		if(mn(t->r) <= m)
		{	
			if(mn(t->r) == m)
			pos = ind(t->r) < id ? (cnt(t->l) + 1 + ps(t->r)) : pos , id = min(id,ind(t->r));
			else
			m = mn(t->r) , pos = cnt(t->l) + 1 + ps(t->r) , id = ind(t->r);
		}
		t->mini = m;
		t->pos = pos;
		t->id = id;
	}
}



void split(pnode t,pnode &l ,pnode &r,int key,int add =0)
{
	if(!t)
	return void(l=r=0);
	push(t);
	int ck = add + cnt(t->l) + 1;
	if(key >ck)
	split(t->r,t->r,r,key,ck) , l = t;
	else
	split(t->l,l,t->l,key,add) , r = t;
	
	updatecnt(t);
	updatemin(t);
}

void merge(pnode &t,pnode l,pnode r)
{
	push(l);
	push(r);

	if(!l || !r)
	t = l ? l : r;
	else if(l->p > r->p)
	merge(l->r , l->r , r) , t = l;
	else
	merge(r->l , l , r->l) , t = r;

	updatecnt(t);
	updatemin(t);
}

void insert(pnode &t,pnode it,int key,int add = 0)
{
	push(t);
	if(!t)
	t = it;
	else if(it->p > t->p)
	split(t,it->l,it->r,key,add) , t = it;
	else
	{
		int ck = add + cnt(t->l) + 1;
		if(key > ck)
		insert(t->r ,it,key,ck);
		else
		insert(t->l,it,key,add);
	}
	updatecnt(t);
	updatemin(t);
}

int getmin(pnode &t)
{
	int ret = ps(t);
	pnode t2 = NULL;
	split(t,t2,t,ret+1);
	reverse(t2);
	merge(t,t2,t);
	split(t,t2,t,2);
	return ret;
}
int main()
{
	int n,a,nxt;
	
	pnode nodes = (pnode)calloc(100000+5,sizeof(node));
	scanf("%d",&n);
	while(n != 0)
	{
		treap = NULL;
		nxt = 0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
		
			nodes[nxt].v = a;
			nodes[nxt].p = rand();
			nodes[nxt].mini = a;
			nodes[nxt].id = nodes[nxt].idx = i;
			nodes[nxt].rev = false;
			nodes[nxt].count = nodes[nxt].pos = 1;
			nodes[nxt].l = nodes[nxt].r = NULL;
			insert(treap,&nodes[nxt],i);
			nxt++;
		}
		for(int i=0;i<n;i++)
			printf("%d\n",i+getmin(treap));
		scanf("%d",&n);
	}
}
