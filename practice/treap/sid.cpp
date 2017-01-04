//15:04
#include<bits/stdc++.h>
using namespace std;
typedef struct node * pnode;
struct node
{
	int p;
	unsigned int v;
	queue<int> q;
	pnode l,r;
};
pnode treap = NULL;
void split(pnode t, unsigned int val , pnode &l ,pnode &r)
{
	if(!t)
	l = r = NULL;
	else if(val > t->v)
	split(t->r , val , t->r , r) , l = t;
	else
	split(t->l , val , l , t->l) , r = t;
}

void merge(pnode &t , pnode l ,pnode r)
{
	if(!l || !r)
	t = l ? l : r;
	else if(l->p > r->p)
	merge(l->r , l->r , r) , t = l;
	else
	merge(r->l , l , r->l) , t = r;
}

void insert(pnode &t , pnode it)
{
	if(!t)
	t = it;
	else if(it->p > t->p)
	split(t, it->v , it->l , it->r) , t = it;
	else
	insert(it->v > t->v ? t->r : t->l , it);
}
void erase(pnode &t, unsigned int val)
{
	if(t->v == val)
	merge(t,t->l , t->r);
	else
	erase(val > t->v ? t->r : t->l ,val);
}

int is_present(pnode t , unsigned int key,char f,int i = 0)
{
	
	if(!t)
	return 0;
	else if(t->v == key)
	{
		if(f == 'S')
		return (t->q).front();
		else if(f == 'I')
		{
			(t->q).push(i);
			return (t->q).front();
		}
		else if(f == 'D')
		{
			int ret = (t->q).front();
			(t->q).pop();
			if((t->q).empty())
			erase(treap,key);
			return ret;
		}
	}
	else if(key > t->v)
	return is_present(t->r,key,f,i);
	else
	return is_present(t->l,key,f,i);
}


int main()
{
	int n,m,rank = 1;
	unsigned int num;
	char c;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%u",&num);
		if(is_present(treap,num,'I',rank))
		{}
		else
		{
			pnode it = new node;
			it->l = it->r = NULL;
			it->v = num;
			it->p = rand();
			(*it).q.push(i);
			insert(treap,it);
		}
		rank++;
	}

	for(int i=1;i<=m;i++)
	{
		scanf(" %c%u",&c,&num);
		if(c == 'S')
		{
			int pos = is_present(treap,num,'S');
			if(pos)
			printf("%d\n",pos);
			else
			printf("NONE\n");
		}	
		else if(c == 'I')
		{
			if(is_present(treap,num,'I',rank))
			{}
			else
			{
				pnode it = new node;
				it->l = it->r = NULL;
				it->v = num;
				it->p = rand();
				(it->q).push(rank);
				insert(treap,it);
			}
			printf("%d\n",rank);
			rank++;
		}
		else if(c == 'D')
		{
			int del = is_present(treap,num,'D');
			if(del)
			printf("%d\n",del);
			else
			printf("NONE\n");
		}
	}

	return 0;
}
