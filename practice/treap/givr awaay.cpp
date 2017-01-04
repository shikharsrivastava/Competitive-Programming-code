//22:17
#include<bits/stdc++.h>
#define cnt(t) (t ? t->count : 0)
#define updatecnt(t) (t ? (t->count = cnt(t->l) + cnt(t->r) + 1) : 0)
using namespace std;
typedef struct node * pnode;
int *arr;
pnode nodes;
int next;
struct node
{
	int p;
	int v;
	int count;
	pnode l,r;
};

int scanint()
{
	int num = 0;
	char c = getchar_unlocked();
	while(c >= '0' && c<= '9')
	{
		num = num *10 + c - '0';
		c = getchar_unlocked();
	}
	return num;
}
struct Treap
{
	pnode tp;
	void init(int n)
	{
		tp = NULL;
	}
	void split(pnode t,pnode &l,pnode &r,int key)
	{
		if(!t)
		return void(l=r=0);
		else if(key > t->v)
		split(t->r,t->r,r,key) , l = t;
		else
		split(t->l,l,t->l,key) , r =t;
		updatecnt(t);
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
	}
	void insert(pnode &t,pnode it)
	{
		if(!t)
		t = it;
		else if(it->p > t->p)
		split(t,it->l,it->r,it->v) , t = it;
		else if(it->v >= t->v)
		insert(t->r,it);
		else
		insert(t->l,it);
		updatecnt(t);
	}
	int get(pnode &t,int key)
	{
		if(!t)
		return 0;
		else if(key > t->v)
		return get(t->r,key);
		else
		return get(t->l,key) + cnt(t->r) + 1;
	}
	void erase(pnode &t,int key)
	{	
		int ic = cnt(t);
		if(!t)
		return;
		else if(t->v == key)
		merge(t,t->l,t->r);
		else if(key > t->v)
		erase(t->r,key);
		else
		erase(t->l,key);
		updatecnt(t);
	}
	void replace(pnode &t,int k1,int k2)
	{
		erase(t,k1);
		ins(t,k2);
	}

	void inss(pnode &t,int k1)
	{
		nodes[next].v = k1;
		nodes[next].p = rand();
		nodes[next].count = 1;
		nodes[next].l = nodes[next].r = NULL;
		insert(t,&nodes[next]);
		next++;
	}
};
struct snode
{
	Treap treap;
};
struct SegmentTree
{
	snode * t;
	int n;
	SegmentTree(int s)
	{
		n = s;
		t = new snode[4*n];
	}
	void build(int l,int r,int id = 1)
	{
		t[id].treap.init(r-l+1);

		for(int i=l;i<=r;i++)
		t[id].treap.ins(t[id].treap.tp,arr[i]);

		if(l == r)
		return;
		int m = (l+r)/2;
		build(l,m,id*2);
		build(m+1,r,id*2+1);
			
	}
	int get(int L,int R,int key,int l,int r,int id = 1)
	{
		
		int ans;
		if(r<L || l>R)
		return 0;
		else if(l>=L && r<=R)
		return t[id].treap.get(t[id].treap.tp,key);
		else
		{
			int m = (l+r)/2;
			return get(L,R,key,l,m,id*2) + get(L,R,key,m+1,r,id*2+1);
		}
	}
	void update(int p,int k1,int k2,int l,int r,int id=1)
	{

		t[id].treap.replace(t[id].treap.tp,k1,k2);
		if(l == r)
		return;
		int m = (l+r)/2;
		if(p>m)
		update(p,k1,k2,m+1,r,id*2+1);
		else
		update(p,k1,k2,l,m,id*2);
	}
};

int main()
{
	int n,q,t,a,b,c;
	//scanf("%d",&n); 
	n = scanint();
	arr = (int*)calloc(n+1,sizeof(int));
	for(int i=1;i<=n;i++)
	arr[i] = scanint();	//scanf("%d",&arr[i]);
	q = scanint();
	nodes = new node[21000000];
	next = 0;
	SegmentTree st(n);
	st.build(1,st.n);
	
	
	//scanf("%d",&q);
	
	while(q--)
	{
		
		//scanf("%d",&t);
		t = scanint();
		if(t == 0)
		{
			//scanf("%d %d %d",&a,&b,&c);
			a = scanint();
			b = scanint();
			c = scanint();
			printf("%d\n",st.get(a,b,c,1,st.n));
		}
		else if(t == 1)
		{
			//scanf("%d %d",&a,&b);
			a = scanint();
			b = scanint();
			st.update(a,arr[a],b,1,st.n);
			arr[a] = b;
		}
	}
	return 0;
}
