//11:02

#include<bits/stdc++.h>
using namespace std;
typedef struct node * pnode;
	
struct node
{
	int p;
	int count;
	int v;
	int sm;
	pnode l,r;
} *treap = NULL;
	
	
int cnt(pnode t)
{
	return t ? t->count : 0;
}
void updatecnt(pnode t)
{
	if(t)
	t->count = cnt(t->l) + cnt(t->r) + 1;
}
int sm(pnode t)
{
	return t ? t->sm : 0;
}
void updatesum(pnode t)
{
	if(t)
	t->sm = sm(t->l) + sm(t->r) + t->v;
}

void split(pnode t , pnode &l ,pnode &r , int key, int add = 0)
{
	if(!t)
	return void(l = r = 0);
	int curr_key = add + cnt(t->l) + 1;
	if(key > curr_key)
	split(t->r , t->r ,r ,key, curr_key) , l = t;
	else
	split(t->l , l , t->l ,key ,add ) , r = t;

	updatecnt(t);
	updatesum(t);
}

void merge(pnode &t ,pnode l,pnode r)
{
	if(!l || !r)
	t = l ? l : r;
	else if(l->p > r->p)
	merge(t->r , t->r , r) , t = l;
	else
	merge(t->l , l , t->l) , t = r;
	updatecnt(t);
	updatesum(t);
}

void insert(pnode &t , int pos ,int val)
{
	pnode it = new node;
	it->v = val;
	it->p = rand();
	it->l = it->r = NULL;
	it->sm = val;
	
	pnode t1 = NULL;
	split(t,t,t1,pos);
	merge(t,t,it);
	merge(t,t,t1);
}

void erase(pnode &t , int pos)
{
	pnode t1,t2;
	t1 = t2 = NULL;
	split(t,t,t1,pos+1);
	split(t,t,t2,pos);
	merge(t,t,t1);
}
int get(pnode &t , int l,int r)
{
	pnode t1,t2;
	t1 = t2 = NULL;
	split(t,t,t1,r+1);
	split(t,t,t2,l);
	int ret = sm(t2);
	merge(t,t,t2);
	merge(t,t,t1);
	return ret;
}

int main()
{
	int n,l,r,pos,val;
	char c;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf(" %c",&c);
		if(c == 'I')
		{
			scanf("%d %d",&pos,&val);
			insert(treap,pos,val);
		}
		else if(c == 'D')
		{
			scanf("%d",&pos);
			erase(treap,pos);
		}
		else if(c == 'G')
		{
			scanf("%d %d",&l,&r);
			printf("%d\n",get(treap,l,r));
		}
	}
	return 0;
}
