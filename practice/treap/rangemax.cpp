/*
	Implicit Treap to get segment tree results of range maximum querry with insert and delete operations
*/

#include<bits/stdc++.h>
using namespace std;
typedef struct node * pnode;
struct node
{
	int val;
	int p;
	int count;
	int mx;
	pnode l,r;
} *treap = NULL;

int cnt(pnode t)
{	
	return t ? t->count : 0;
}
int getmx(pnode t)
{
	return t ? t->mx : -1000000000;
}
void updatecnt(pnode t)
{
	if(t)
	t->count = cnt(t->l) + cnt(t->r) + 1;
}

void update(pnode t)
{
	if(t)
	t->mx = max(t->val,max(getmx(t->l),getmx(t->r))); 
}

void split(pnode t , pnode &l , pnode &r , int key ,int add = 0)
{
	if(!t)
	return void(l = r =0);

	int curr_key = add + cnt(t->l) + 1;
	if(key > curr_key)
	split(t->r , t->r , r , key , curr_key) , l = t;
	else
	split(t->l , l , t->l , key ,add) , r = t;
	
	updatecnt(t);
	update(t);
}

void merge(pnode &t , pnode l , pnode r)
{
	if(!l || !r)
	t = l ? l: r;
	else if(l->p > r->p)
	merge(l->r , l->r , r) , t = l;
	else
	merge(r->l , l , r->l) , t = r;

	updatecnt(t);
	update(t);
}

void insert(pnode &t , int pos , int val)
{
	pnode it = new node;
	it-> val = val;
	it-> p = rand();
	it->count = 0;
	it->mx = val;
	it->l = it->r = NULL;
	
	pnode t1,t2;
	t1 = t2 = NULL;
	split(t,t1,t2,pos);
	merge(t1,t1,it);
	merge(t,t1,t2);
}

void erase(pnode &t,int pos)
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
	/* Spliting the treap as the following   */
	/* [1..........................end]	 */
	/* [1...............r] [r+1....end]
		 t		  t1
	/* [1....l-1] [l....r] [r+1....end]	 */
	/*     t	 t2	   t1		 */
	split(t,t,t1,r+1);			
	split(t,t,t2,l);		
	int ans = getmx(t2);
	merge(t,t,t2);
	merge(t,t,t1);
	return ans;
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
