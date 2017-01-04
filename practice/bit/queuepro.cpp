//2:18 - > 20 min total

/*
	A question like ordering soldiers
	First sort all the people according to height h
	Now if the inversion of the smallest person is inv , its position in final queue is inv+1 as no other position will give it this inversion inv
	
	Now this position is marked and final so other people will search in remaining positions which we find using segment tree
	We initialize a segment tree with all 1 at nodes and count of ones in segments
	We mark those positions which are filled till current processing by putting 0 there
	Now we see , when we process any person i , the positions which are already occupied will not contrbute to its inversions as those people are 
	smaller than or equal to the person i and there positions are final since we came from the base case , so if the inversion of the ith person is inv , we 	 search for inv+1 th position in the remaining position
	We use segment tree for that because it will do that in O(nlogn) , without binary search
	In bit we would have to use binary search which gives O(nlog*2(n))
*/
#include<bits/stdc++.h>
using namespace std;

struct segtree
{
	int *t;
	int n;
	
	segtree(int s=1)
	{
		n=s;
		t=(int*)calloc(4*n+2,sizeof(int));
	}
	void reset(int s)
	{
		free(t);
		n=s;
		t=(int*)calloc(4*n+2,sizeof(int));
		construct(1,n,1);
	}
	
	void construct(int s,int e,int id)
	{
		if(s==e)
		{t[id]=1;return;}
		
		int m=(s+e)/2;
		construct(s,m,id*2);
		construct(m+1,e,id*2+1);
		
		t[id]=t[id*2]+t[id*2+1];
	}

	void update(int p,int v,int s,int e,int id=1)
	{
		t[id]--;
		if(s==e)
		return;
		
		int m=(s+e)/2;
		if(p<=m)
		update(p,v,s,m,id*2);
		else
		update(p,v,m+1,e,id*2+1);
	}
	
	int find(int sum,int s,int e,int id=1)// finding position in O(log(n)) without binary search
	{
		if(s==e)
		return s;
	
		int m=(s+e)/2;
		if(t[id*2] >= sum)
		return find(sum,s,m,id*2);
		else
		return find(sum-t[id*2],m+1,e,id*2+1);
	}	
	
	
};

struct people
{
	int h;
	int inv;
	int id;
};

bool so(const people a, const people b)
{		
		if(a.h==b.h)
		return a.inv<b.inv;
		return a.h<b.h;
}

int main()
{
	int t,n,pos,*ans;
	people *p;
	scanf("%d",&t);
	segtree s;
	while(t--)
	{
		scanf("%d",&n);
		s.reset(n);
		ans=(int*)calloc(n+1,sizeof(int));
		p=(people*)calloc(n+1,sizeof(people));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&p[i].h);
			p[i].id=1;		
		}
		for(int i=1;i<=n;i++)
		scanf("%d",&p[i].inv);
	
		sort(p+1,p+n+1,so);
		// Starting from the base case , i.e the person for smallest height whose positio is know for sure and moving up to find final positions of 
		// everyone as it is in ascending order so every position found is final and correct
		for(int i=1;i<=n;i++)
		{

			pos=s.find(p[i].inv+1,1,n,1);	// final position for ith person in sorted list found
			s.update(pos,-1,1,n,1);		// Marking that position as 0
			ans[pos]=p[i].h;	
		}
		for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
		printf("\n");
		free(ans);
		free(p);
	}
}
