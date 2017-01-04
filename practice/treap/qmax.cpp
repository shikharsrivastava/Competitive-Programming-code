//17:24
#include<bits/stdc++.h>
using namespace std;
#define cnt(t) ((t) ? (t)->count : 0)
#define getmx(t) ((t) ? (t)->mx : -1000000000)
#define updatemx(t) ((t) ? (t)->mx = max((t)->v,max(getmx((t)->l),getmx((t)->r))) : 0)
#define updatecnt(t) ((t) ? ((t)->count = cnt((t)->l) + cnt((t)->r) + 1) : 0)
typedef struct node* pnode;
struct node
{
	int v;
	int p;
	int mx;
	int count;
	pnode l,r;
} *treap,*tnodes;



void split(pnode t , pnode &l ,pnode &r, int key ,int add = 0)
{
	if(!t)
	return void(l = r = 0);
	int ck = add + cnt(t->l) + 1;
	if(key > ck)
	split(t->r , t->r , r , key,ck) , l = t;
	else
	split(t->l , l , t->l , key ,add) , r = t;
	
	updatecnt(t);
	updatemx(t);
}

void merge(pnode &t , pnode l , pnode r)
{
	if(!l || !r)
	t = l ? l : r;
	else if(l->p > r->p)
	merge(l->r , l->r , r) , t = l;
	else 
	merge(r->l, l , r->l) , t = r;
	
	updatecnt(t);
	updatemx(t);
}

void insert(pnode &t , int pos,pnode it,int add = 0)
{
	if(!t)
	t = it;
	else if(it->p > t->p)
	split(t,it->l,it->r,pos,add) , t = it;
	else
	{
		int ck = add + cnt(t->l) + 1;
		if(pos > ck)
		insert(t->r , pos , it , ck);
		else
		insert(t->l , pos , it , add);
	}
	updatecnt(t);
	updatemx(t);
}

int get(pnode &t , int l,int r)
{	
	pnode t1,t2;
	t1 = t2 = NULL;
	split(t,t,t1,r+1);
	split(t,t,t2,l);
	int ret = getmx(t2);
	merge(t,t,t2);
	merge(t,t,t1);
	return ret;
}

int main()
{
	int n,x,y,nxt;
	char c;
	scanf("%d",&n);
	treap = NULL;
	tnodes = (pnode)calloc(100005,sizeof(node));
	nxt = 1;
	for(int i=1;i<=n;i++)
	{
		scanf(" %c %d %d",&c,&x,&y);
		if(c == 'A')
		{
			tnodes[nxt].v = tnodes[nxt].mx = x;
			tnodes[nxt].p = rand();
			tnodes[nxt].count = 0;
			tnodes[nxt].l = tnodes[nxt].r = NULL;
			insert(treap,y,&tnodes[nxt]);
			nxt++;
		}
		else
		printf("%d\n",get(treap,x,y));
	}
	return 0;
}

