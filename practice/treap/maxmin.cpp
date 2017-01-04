//10:23
#include<bits/stdc++.h>
using namespace std;
typedef struct node * pnode;
#define cnt(t) (t ? t->count : 0)
#define updatecnt(t) (t ? (t->count = cnt(t->l) + cnt(t->r) + 1 : 0))
#define getmax(t) (t ? t->mx : -1)

struct node
{
	int v;
	int p;
	int count;
	int mx;
	int mn;
	pnode l,r;
};

void updateans(pnode t)
{
	if(t)
	{	
		
	}
}

void split(pnode t,pnode &l,pnode &r,int key)
{
	if(!t)
	return void (l=r=0);
	if(key > t->v)
	split(t->r,t->r,r,key) , l = t;
	else
	split(t->l,l,t->l,key) , r = t;
	updatecnt(t);
	updateans(t);
}
void merge(pnode &t,pnode l,pnode r)
{
	if(!l || !r)
	t = l ? l : r;
	else if(l->p > r->p)
	merge(l->r,l->r,r) , t = l;
	else
	merge(r->l,l,r->l) , t = r;
	updatecnt(t);
	updateans(t);
}

void insert(pnode&t,pnode it)
{
	if(!t)
	t = it;
	else if(it->p > t->p)
	split(t,it->l,it->r,it->v) , t = it;
	else if(it->v > t->v)
	insert(t->r,it);
	else
	insert(t->l,it);
	updatecntt(t);
	updateans(t);
}

void erase(pnode &t ,int key)
{
	if(!t)
	return ;
	else if(key == t->v)
	merge(t,t->l,t->r);
	else if(key > t->v)
	erase(t->r,key);
	else
	erase(t->l,key);
	updatecnt(t);
	updateans(t);
}


