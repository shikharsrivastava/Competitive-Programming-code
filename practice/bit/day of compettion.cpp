//22:44

/*
	First sort the first array accoring to ranks
	Then when we reach any rank i int the first competetion , Only possible candidates who can be better than player i are those having lesser ranks 
	than player i in first competetion.
	In a bit , mark player i's rank in third competetion at the index j = rank of player i in second competetion
	
	In this way , all the indexes before j is n the bit have rank less than that of i,s in second competetion ,but only some are filled till now
	Those that are filled are players who appeared before i in the first competetion , because we are moving in the sorted list
	
	Now the player i can only be excellent if in third competetion it appears before the all the people who appeared before him in 2nd round ,
	i.e its rank in 3rd round < minimum rank of all the players before it in bit in 3rd round

	This can be easily done using a bit where we store for a player with rank i ,in first round ,at index id = its rank in second round value v,its
	rank in 3rd round
	
	And Querry gives us the minimum in range
*/
#include<bits/stdc++.h>
using namespace std;

struct bit
{
	int *b;
	int n;
	bit(int s)
	{
		n=s;
		b=(int*)calloc(n+1,sizeof(int));
	}
	void reset(int s)
	{
		free(b);
		n=s;
		b=(int*)calloc(n+1,sizeof(int));	
	}

	void insert(int p,int v=1)
	{
		while(p<=n)
		{
		b[p]+=1;
		p+=p& -p;
		}
	}
	int sum(int p)
	{
		int ans=0;
		while(p>0)
		{
		ans+=b[p];
		p-=p& -p;
		}
	return ans;	
	}
};

struct pl
{
	int rank;
	int id;
};

bool so(const pl a, const pl b)
{	
		return a.rank<b.rank;
}

int main()
{	

	int t,n,*b,*c,ans,idx;
	pl *a;
	scanf("%d",&t);
	bit ba(1),bb(1),bc(1);
	while(t--)
	{
		scanf("%d",&n);
		a=(pl*)calloc(n+1,sizeof(pl));
		b=(int*)calloc(n+1,sizeof(int));
		c=(int*)calloc(n+1,sizeof(int));
		ba.reset(n);
		bb.reset(n);
		bc.reset(n);		
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&a[i].rank,&b[i],&c[i]);
			a[i].id=i;
		}
		sort(a+1,a+n+1,so);

		ans=0;
		for(int i=1;i<=n;i++)
		{
			idx=a[i].id;
			if(bb.sum(b[idx]) == 0 || bc.sum(c[idx]) == 0)
			ans++;
			bb.insert(b[idx]);
			bc.insert(c[idx]);
		}
		printf("%d\n",ans);
		free(a);
		free(b);
		free(c);
	}	
}
