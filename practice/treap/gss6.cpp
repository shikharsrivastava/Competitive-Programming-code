/*
	Using Implicit treap 
*/

#include<bits/stdc++.h>
using namespace std;
typedef struct node * pnode;
typedef long long int lli;
#define getsum(t) ((t) ? (t)->sm : 0)
#define getlftsum(t) (t ? (t)->lftsum : -1000000000)
#define getrgtsum(t) ((t) ? (t)->rgtsum : -1000000000)
#define getans(t) ((t) ? (t)->ans : -1000000000)	
#define getnode(t) ((t) ? (t)->v : 0)
#define cnt(t) ((t) ? (t)->count : 0)
int nxt = 1;
struct node
{
	int p;
	int count;
	int v;
	int ans;
	int sm;
	int lftsum;
	int rgtsum;
	pnode l,r;
} *treap = NULL , *tnodes;
	
	
void updatecnt(pnode t)
{
	if(t)
	t->count = cnt(t->l) + cnt(t->r) + 1;
}

void updatesum(pnode t)
{
	if(t)
	{
		// Merging left and current node
		t->ans = max(getrgtsum(t->l)+t->v ,max(getans(t->l) , t->v));
		t->lftsum = max(getlftsum(t->l) , getsum(t->l)+ t->v);
		t->rgtsum = max(t->v , getrgtsum(t->l) + t->v);
		t->sm = getsum(t->l) + t->v;
		//Merging with right node now
		t->ans = max(getans(t) , max(getans(t->r) , getrgtsum(t)+getlftsum(t->r)));
		t->lftsum = max(getlftsum(t) , getsum(t) + getlftsum(t->r));
		t->rgtsum = max(getrgtsum(t->r) , getrgtsum(t)+getsum(t->r));
		t->sm = getsum(t) + getsum(t->r);
	}
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
	merge(l->r , l->r , r) , t = l;
	else
	merge(r->l , l , r->l) , t = r;
	updatecnt(t);
	updatesum(t);
	
}
// Insert function is same as normal treap , other implementation gives TLE
void insert(pnode &t , pnode it,int pos,int add = 0)
{
	if(!t)
	t = it;
	else if(it->p > t->p)	//Passing the current add to split , so that the correct implicit keys can be calculated from the root , not the current node
	split(t,it->l,it->r,pos,add) , t = it;		// Separating the subtree with implicit keys < pos in it->l and >= pos in it->r
	else
	{
		int curr_key = add + cnt(t->l) + 1;
		if(pos > curr_key)
		insert(t->r,it,pos,curr_key);
		else 
		insert(t->l,it,pos,add);
	}	
	updatecnt(t);
	updatesum(t);
}

void erase(pnode &t , int pos , int add =0)
{
	if(!t)
	return;
	int curr_key = add + cnt(t->l) + 1;
	if(pos == curr_key)
	merge(t,t->l,t->r);
	else if(pos > curr_key)
	erase(t->r , pos , curr_key);
	else
	erase(t->l , pos ,add);
	updatecnt(t);
	updatesum(t);	
}
int get(pnode &t , int l,int r)
{
	pnode t1,t2;
	t1 = t2 = NULL;
	split(t,t,t1,r+1);
	split(t,t,t2,l);
	int ret = getans(t2);
	merge(t,t,t2);
	merge(t,t,t1);
	return ret;
}
void replace(pnode &t ,int pos , int val,int add = 0)
{
	if(!t)
	return;
	int curr_key = add + cnt(t->l) + 1;
	if(pos == curr_key)
	t->v = val;
	else if(pos > curr_key)
	replace(t->r , pos , val, curr_key);
	else
	replace(t->l , pos , val ,add);
	
	updatecnt(t);
	updatesum(t);
}

int main()
{
	int n,l,r,pos,q,val;
	char c;
	tnodes = (pnode)calloc(2*100002,sizeof(node));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&val);
		tnodes[nxt].v = val;
		tnodes[nxt].p = rand();
		tnodes[nxt].l = tnodes[nxt].r = NULL;
		insert(treap,&tnodes[nxt],i);
		nxt++;
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf(" %c",&c);
		if(c == 'I')
		{
			scanf("%d %d",&pos,&val);
			tnodes[nxt].v = val;
			tnodes[nxt].p = rand();
			tnodes[nxt].l = tnodes[nxt].r = NULL;
			insert(treap,&tnodes[nxt],pos);
			nxt++;
		}
		else if(c == 'D')
		{
			scanf("%d",&pos);
			erase(treap,pos);
		}
		else if(c == 'Q')
		{
			scanf("%d %d",&l,&r);
			printf("%d\n",get(treap,l,r));
		}
		else if(c == 'R')
		{
			scanf("%d %d",&pos,&val);
			replace(treap,pos,val);
		}
	}
	return 0;
}
