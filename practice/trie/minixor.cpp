
#include<bits/stdc++.h>
using namespace std;

class trie
{
	public:
	struct node
	{	
		node *l;
		node *r;
		int c;
	} *t;
	int m;
	int cnt;
	trie()
	{
		t=(node *)calloc(1,sizeof(node));
	}

	void insert(int n,node *no,int k=15)
	{
		if(k<0)
		{
		no->c++;
		return;
		}

		int x=(n>>k)&1;
		if(x)
		{
			if(no->r == NULL)
			no->r=(node*)calloc(1,sizeof(node));
			insert(n,no->r,k-1);

		}
		else
		{
			if(no->l == NULL)
			no->l=(node*)calloc(1,sizeof(node));
			insert(n,no->l,k-1);
		}	
	}
	bool del(int n,node *no,int k=15)
	{
		if(k<0)
		{
			no->c--;
			if(no->c)
			return false;
			else
			return true;
		}
		int x=(n>>k)&1;
		if(x)
		{
			if(del(n,no->r,k-1))
			{	free(no->r);
				no->r=NULL;
			}
			if(no->r == NULL and no->l ==NULL)
			return true;
			else
			return false;
		}
		else
		{
			if(del(n,no->l,k-1))
			{
				free(no->l);
				no->l=NULL;
			}
			if(no->l ==NULL && no->r==NULL)
			return true;
			else
			return false;
		}
	}
	
	void findmin(int n,node *no,int k=15)
	{
		if(k<0)
		{
		cnt=no->c;
		return;
		}
		int x=(n>>k)&1;
		if(x)
		{
			if(no->r != NULL)
			findmin(n,no->r,k-1);
			else
			{findmin(n,no->l,k-1);m|=1<<k;}
		}
		else
		{
			if(no->l != NULL)
			findmin(n,no->l,k-1);
			else
			{findmin(n,no->r,k-1);m|=1<<k;}
		}
	}
	
};
int main()
{
	int n,q,k,ch,l,r,*a,*xr;
	scanf("%d %d",&n,&q);
	a=(int*)calloc(n+1,sizeof(int));
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
		
	int BS=sqrt(n);
	int BN=n/BS+2;
	//printf("BS = %d , BN = %d\n",BS ,BN);
	xr=(int*)calloc(BN+2,sizeof(int));
	int i,b=1;
	trie tr[BN];
	
	for(i=1;i+BS<=n;i+=BS)
	{
		for(int j=i;j<=i+BS-1;j++)
		tr[b].insert(a[j],tr[b].t);
		b++;
	}
	for(;i<=n;i++)
	tr[b].insert(a[i],tr[b].t);
		
	for(int qr=1;qr<=q;qr++)
	{
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d %d",&l,&r);
			int st=ceil((float)l/BS);
			int en=floor((float)r/BS);
			int m=10000000;
			int cnt=0;
			
				
				for(int i=l;(i<=r) && (i<=st*BS);i++)
				{
					if((a[i]^xr[st]) <m)
					{
						m=a[i]^xr[st];
						cnt=1;
					}
					else if((a[i]^xr[st]) == m)
					cnt++;
				}
				//printf("in = %d ,cnt =%d\n",m,cnt);	
				st++;
				if(en >=st-1)
				{
				for(int i=en*BS+1;i<=r;i++)
				{
					if((a[i]^xr[en+1]) <m)
					{
						m=a[i]^xr[en+1];
						cnt=1;
					}
					else if((a[i]^xr[en+1]) == m)
					cnt++;
				}

			//printf("in = %d ,cnt =%d\n",m,cnt);
			//printf("Till here\n");
			for(int i=st;i<=en;i++)
			{
				tr[i].m=0;
				tr[i].cnt=0;
				tr[i].findmin(xr[i],tr[i].t);
				if(tr[i].m<m)
				{
				m=tr[i].m;
				cnt=tr[i].cnt;
				}
				else if(tr[i].m == m)
				cnt+=tr[i].cnt;
			}
			}
			printf("%d %d\n",m,cnt);
		}	
		else
		{
			scanf("%d %d %d",&l,&r,&k);
			int st=ceil((float)l/BS);
			int en=floor((float)r/BS);
			
			for(int i=l;(i<=r) && (i<=st*BS);i++)
			{
						
			tr[st].del(a[i],tr[st].t);
			a[i]^=k;
			tr[st].insert(a[i],tr[st].t);
			
			}
			st++;
			if(en>=st-1)
			{
			for(int i=en*BS+1;i<=r;i++)
			{

			tr[en+1].del(a[i],tr[en+1].t);
			a[i]^=k;
			tr[en+1].insert(a[i],tr[en+1].t);
			}
			for(int i=st;i<=en;i++)
			xr[i]^=k;
			}		
		}
	}
	return 0;
}
