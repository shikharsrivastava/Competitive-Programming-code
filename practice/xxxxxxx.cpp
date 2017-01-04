    #include<bits/stdc++.h>
    #define INF (100000 + off++)
    using namespace std;
    typedef struct node* pnode;
    typedef long long int lli;
    #define getsum(t) (t ? t->sum : 0)
    #define updatesum(t) (t ? (t->sum = getsum(t->l) + getsum(t->r) +(lli)(t->v)) : 0)
    #define N 50005
    int nxtarr[N],prevarr[N];
    lli arr[N];
    struct node
    {
    	int key,p;
    	lli sum,v;
    	pnode l,r;
    } tnodes[100006];
    int n , nxt = 0 , off = 0;
    struct treap
    {
    	pnode t;
    	void init()
    	{
    		t = NULL;
    	}
    	void split(pnode t,pnode &l,pnode &r,int key)
    	{
    		if(t == NULL)
    		return void (l = r = NULL);
    		else if(t->key > key)
    		split(t->l,l,t->l,key) , r = t;
    		else
    		split(t->r,t->r,r,key) , l = t;
    		updatesum(l);
    		updatesum(r);
    	}
     
    	void merge(pnode &t ,pnode l,pnode r)
    	{
    		if(!l || !r)
    		t = l ? l : r;
    		else if(l->p > r->p)
    		merge(l->r,l->r,r) , t = l;
    		else
    		merge(r->l,l,r->l) , t = r;
    		updatesum(t);
    	}
    	void insert(pnode &t,pnode it)
    	{
    		if(!t)
    		t = it;
    		else if(it->p >t->p)
    		split(t,it->l,it->r,it->key) , t = it;
    		else if(it->key > t->key)
    		insert(t->r,it);
    		else
    		insert(t->l,it);
    		updatesum(t);
    	}
    	lli findsum(pnode &t ,int key)
    	{
    	
    		if(!t)
    		return 0;
    		else if(key >= t->key)
    		return findsum(t->r,key);
    		else
    		return findsum(t->l,key) + getsum(t->r) + t->v;
    	}
    	void erase(pnode &t,int key)
    	{
    		if(!t)
    		return;
    		if(key > t->key)
    		erase(t->r,key);
    		else if(key < t->key)
    		erase(t->l,key);
    		else
    		merge(t,t->l,t->r);
		updatesum(t);
    	}
    	
    	void ins(int key,lli v)
    	{
    		tnodes[nxt].key = key;
    		tnodes[nxt].p = rand();
    		tnodes[nxt].v = tnodes[nxt].sum = v;
    		tnodes[nxt].l = tnodes[nxt].r = NULL;
    		insert(t,&tnodes[nxt]);
    		nxt++;
     
    	}
    } st[4*N];
     
    void build(int s= 1,int e = n,int id =1)
    {
    	st[id].init();
    	if(s == e)
    		st[id].ins(nxtarr[s],arr[s]);
    	else
    	{
    		int m = (s+e)>>1;
    		build(s,m,id*2);
    		build(m+1,e,id*2+1);
    		for(int i=s;i<=e;i++)
    		st[id].ins(nxtarr[i],arr[i]);
    	}
    	return;
    }
     
    void update(int pos,int rem,int ad,int v,int s=1,int e =n,int id =1)
    {
    	
    	st[id].erase(st[id].t,rem);
    	st[id].ins(ad,v);
    	if(s==e)
    	return;
    	int m = (s+e)>>1;
    	if(pos <= m )
    	update(pos,rem,ad,v,s,m,id*2);
    	else
    	update(pos,rem,ad,v,m+1,e,id*2+1);
    }
     
    lli querysum(int l,int r,int s = 1,int e = n,int id=1)
    {
    	if(s>r || e<l)
    	return 0;
    	else if(s>=l && e <=r)
    	return st[id].findsum(st[id].t,r);
    	else 
    	{
    		int m = (s+e)>>1;
    		return querysum(l,r,s,m,id*2) + querysum(l,r,m+1,e,id*2+1);
    	}
    }
     
    int main()
    {
    	map <int,set<int> > mp;
    	set<int>::iterator it;
    	scanf("%d",&n);
    	char ch;
    	int m,l,r;
    	treap tr;
    	tr.init();
    	lli a;
    	for(int i=1;i<=n;i++)
    	{
    		scanf("%lld",&arr[i]);
    		mp[arr[i]].insert(i);	
    	}
    	
    	for(int i=1;i<=n;i++)
    	{
    		it = lower_bound(mp[arr[i]].begin(),mp[arr[i]].end(),i+1);
    		if(it == mp[arr[i]].end())
    			nxtarr[i] = INF;
    		else
    		nxtarr[i] = *it;
    		
    		it = lower_bound(mp[arr[i]].begin(),mp[arr[i]].end(),i);
    		if(it == mp[arr[i]].begin())
    		prevarr[i] = -INF;
    		else
    		it-- ,prevarr[i] = *(it);
    				
    	}
    	
    	
    	build();
     
    	scanf("%d",&m);
    	for(int i=1;i<=m;i++)
    	{
    		scanf(" %c %d %d",&ch,&l,&r);
    		if(ch == 'Q')
    		printf("%lld\n",querysum(l,r));
    		else
    		{
    			int temp = nxtarr[l];
    			
    			mp[arr[l]].erase(l);
    			arr[l] = r;
    			mp[arr[l]].insert(l);
    			int pos;
     
    			if(prevarr[l] > 0)
    			{
    				pos = prevarr[l];
    				update(pos,nxtarr[pos],nxtarr[l],arr[pos]);
    				nxtarr[prevarr[l]] = nxtarr[l];
    			} 
    			if(nxtarr[l] <= n)	
    					prevarr[nxtarr[l]] = prevarr[l];
    				
    						
    			
    			it = lower_bound(mp[r].begin(),mp[r].end(),l+1);
    			if(it == mp[arr[l]].end())
    			{
    				int val = INF;
    				update(l,nxtarr[l],val,r);
    				nxtarr[l] = val;
    			}
    			else
    			{
    				update(l,nxtarr[l],(*it),arr[*it]);
    				nxtarr[l] = *it , prevarr[*it] = l;
    			}
    			it = lower_bound(mp[arr[l]].begin(),mp[arr[l]].end(),l);
    			if(it == mp[arr[l]].begin())
    			prevarr[l] = - INF;
    			else
    			{
    				it-- , prevarr[l] = *it , 
    				update((*it),nxtarr[*it],l,arr[l]);				
    				nxtarr[*it] = l;
    			}
    	
    		}
    	}
    		return 0;
    } 
