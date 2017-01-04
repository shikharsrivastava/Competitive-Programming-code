/*
	Dynammic array using implicit treap
*/
#include<bits/stdc++.h>
using namespace std;
typedef struct node * pnode;
struct node
{
	int p;
	int val;
	int cnt;
	pnode l,r;
};

int count(pnode t)
{	
	return t ? t->cnt : 0;
}

void updatecnt(pnode t)
{
	if(t)
	t->cnt = count(t->l) + count(t->r) + 1;
}

void split(pnode t, int key , pnode &l,pnode &r , int add = 0)
{
	if(!t)
	return void(l = r = 0);
	
	int curr_key = add + count(t->l) + 1;
	if(key > curr_key)
	split(t->r , key , t->r , r ,curr_key) , l = t;
	else
	split(t->l , key , l , t->l , add) , r = t;
	
	updatecnt(t);
}

void merge(pnode &t , pnode l, pnode r)
{
	if(!l || !r)
	t = l ? l : r;
	else if( l->p > r->p)
	merge(l->r , l->r , r) , t = l;
	else
	merge(r->l , l , r->l) , t = r;
	updatecnt(t);
}

void insert(pnode &t , int pos , int val)
{
	pnode it = new node;
	it->p = rand();
	it->val = val;
	it->l = it->r = NULL;
	pnode t1 , t2;
	t1 = t2 = NULL;
	split(t,pos,t1,t2);
	merge(t1,t1,it);
	merge(t,t1,t2);
}

void erase(pnode &t , int pos , int add = 0)
{
	if(!t)
	return;
	
	int curr_key = add + count(t->l) + 1;
	if(pos == curr_key)
	merge(t,t->l,t->r);
	else if(pos > curr_key)
	erase(t->r,pos,curr_key);
	else
	erase(t->l,pos,add);

	updatecnt(t);
}

int get(pnode t , int pos,int add = 0)
{
	if(!t)
	return 0;

	int curr_key = add + count(t->l) + 1;

	if(pos == curr_key)
	return t->val;
	else if(pos > curr_key)
	return get(t->r , pos , curr_key);
	else
	return get(t->l , pos , add); 
}
int main()
{
	pnode treap = NULL;
	int n,pos,val;
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
			scanf("%d",&pos);
			printf("%d\n",get(treap,pos));
		}
	}

	return 0;
}

