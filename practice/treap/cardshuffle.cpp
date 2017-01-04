#include<bits/stdc++.h>
using namespace std;
#define cnt(t) (t ? t->count : 0)
#define updatecnt(t) (t ? (t->count = cnt(t->l) + cnt(t->r) + 1) : 0)
#define reverse(t) (t ? (t->lazy ^= true) : 0)
typedef struct node* pnode;
struct node
{
	int v;
	int p;
	bool lazy;
	int count;
	pnode l,r;
} *treap , *tnodes;

void push(pnode t)
{
	if(t && t->lazy)
	{
		t->lazy ^= true;
		swap(t->l,t->r);
		if(t->l)
		t->l->lazy ^= true;
		if(t->r)
		t->r->lazy ^= true;
	}
}

void split(pnode t ,pnode &l ,pnode &r ,int pos, int add = 0)
{
	if(!t)
	return void(l = r = 0);
	push(t);
	int ck = add + cnt(t->l) + 1;
	if(pos > ck)
	split(t->r , t->r , r , pos ,ck) , l = t;
	else
	split(t->l , l ,t->l , pos ,add) , r = t;
	
	updatecnt(t);
}

void merge(pnode &t ,pnode l,pnode r)
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
}

void insert(pnode &t , pnode it , int pos ,int add = 0)
{
	push(t);
	if(!t)
	t = it;
	else if(it->p >t->p)
	split(t , it->l , it->r ,pos,add) , t = it;
	else
	{
		int ck = add + cnt(t->l) + 1;
		if(pos > ck)
		insert(t->r , it , pos , ck);
		else
		insert(t->l , it , pos , add);
	}
	updatecnt(t);
}

void shuffle(pnode &t ,int a ,int b, int c)
{
	pnode ta , tb , tc;
	ta = tb = tc = NULL;
	split(t,ta,t,a+1);
	split(t,tb,t,b+1);
	merge(t,ta,t);
	split(t,tc,t,c+1);
	reverse(tb);
	merge(t,tb,t);
	merge(t,tc,t);	
}

int get(pnode t , int pos , int add = 0)
{
	if(!t)
	return 0;
	push(t);

	int ck = add + cnt(t->l) + 1;
	
	if(ck == pos)
	return t->v;
	else if(pos > ck)
	return get(t->r , pos , ck);
	else
	return get(t->l , pos ,add);
}


int main()
{
	int n,nxt,m,a,b,c;
	nxt = 1;
	treap = NULL;
	tnodes = (pnode)calloc(100050,sizeof(node));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		tnodes[nxt].v = i;
		tnodes[nxt].p = rand();
		tnodes[nxt].lazy = false;
		tnodes[nxt].l = tnodes[nxt].r = NULL;
		tnodes[nxt].count = 0;
		insert(treap , &tnodes[nxt],i);
		nxt++;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		shuffle(treap,a,b,c);
	}
	for(int i=1;i<=n;i++)
	printf("%d ",get(treap,i));
	printf("\n");
}
