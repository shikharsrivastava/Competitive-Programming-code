//21:10
#include<bits/stdc++.h>
using namespace std;
typedef struct node * pnode;
#define getval(t) (t ? t->v : 0)
#define getsum(t) (t ? t->sum : 0)
#define usm(t) (t ? t->sum = getsum(t->r) + getsum(t->l) + getval(t) : 0)

int ind = 0;
struct node
{
	int p;
	int v;
	int key;
	int sum;
	pnode l,r;
} allnodes[100000];

struct treap
{
	node *t = NULL;
	
	void split(pnode t,pnode &l,pnode &r,int key)
	{
		if(!t)
		return void( l = r = NULL);
		else if(t->key > key)
		split(t->l,l,t->l,key) , r = t;
		else 
		split(t->r,t->r,r,key) , l = t;

		usm(l);
		usm(r);
	}

	void merge(pnode &t,pnode l,pnode r)
	{
		if(!l || !r)
		t = l ? l : r;
		else if(l->p > r->p)
		merge(l->r,l->r,r) , t = l;
		else
		merge(r->l,l,r->l) , t = r;
		usm(t);		
	}

	void insert(pnode &t,pnode it)
	{
		if(!t)
		t = it;
		else if(it->p > t->p)
		split(t,it->l,it->r,it->key) , t=it;
		else
		insert(it->key > t->key ? t->r : t->l , it);
		usm(t);
	}

	void erase(pnode &t,int key)
	{
		if(!t)
		return;
		else if(key > t->key)
		erase(t->r,key);
		else if(key< t->key)
		erase(t->l,key);
		else
		merge(t,t->l,t->r);
		usm(t);
	}
	int findsum(pnode t,int key)
	{
		if(!t)
		return 0;
		else if(key >= t->key)
		findsum(t->r,key);
		else if(key < t->key)
		return findsum(t->l,key) + getsum(t->r) + t->v;	
	}
	void ins(pnode &t,int key)
	{
		allnodes[ind].p = rand();
		allnodes[ind].v = allnodes[ind].key = allnodes[ind].sum = key;
		allnodes[ind].l = allnodes[ind].r = NULL;
		insert(t,&allnodes[ind]);
		ind++;
	}
} st*[4*50000];

void build(int s,int e,int id)
{
	for(int i=s;i<=e;i++)
	st[id].ins(st[id].t,nxt[s]);
	if(s==e)
	return;
	
	int m = (s+e)>>1;
	build(s,m,id*2);
	build(m+1,e,id*2+1);
}

void update(int p,int prevval,int s,int e,int id)
{
	st[id].erase(st[id].t,prevval);
	if(s==e)
	return;
	int m = (s+e)>>1;
	if(p<=m)
	update(p,prevval,s,m,id*2);
	else
	update(p,prevval,m+1,e,id*2+1);
}

int getans(int l,int r,int s,int e,int id)
{
	if(s>r || e<l)
	return 0;
	else if(s>=l && e<=r)
	return st[id].findsum(st[id].t,r);
	else
	{
		int m = (s+e)>>1;
		return getans(l,r,s,m,id*2) + getans(l,r,m+1,e,id*2+1);
	}
}

void update_arr(int p,)

int main()
{
	
}
