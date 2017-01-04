//18:09
/*Simple 2D bit with range querry and point update*/
#include<bits/stdc++.h>
using namespace std;

struct bit
{
	int *b;
	bit()
	{
		b=(int*)calloc(1025,sizeof(int));
	}
	
	void update(int pos,int v)
	{
		while(pos<=1024)
		{
		b[pos]+=v;
		pos+=pos & -pos;	
		}

	}
	int sum(int pos)
	{		
		int ans=0;
		while(pos>0)
		{
		ans+=b[pos];
		pos-=pos &-pos;
		}
		return ans;
	}
	void reset()
	{
		free(b);
		b=(int*)calloc(1025,sizeof(int));
	}
};

struct twoDbit
{
	bit *b;
	twoDbit()
	{
		b=(bit*)calloc(1025,sizeof(bit));	
	}
	
	void update(int x,int y,int v)
	{
		while(x<=1024)
		{
		b[x].update(y,v);
		x+=x& -x;		
		}
	}
	int sum(int x,int y)
	{
		int ans=0;
		while(x>0)
		{
		ans+=b[x].sum(y);
		x-=x& -x;
		}
		return ans;
	}
	void reset()
	{
		for(int i=0;i<1025;i++)
			b[i].reset();
	}
};

int main()
{
	int t,n,x1,y1,x2,y2,v;
	scanf("%d",&t);
	char s[4];
	twoDbit b;
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s);
		b.reset();
		while(s[1] != 'N')
		{
			if(s[1]=='E')
			{
				scanf("%d %d %d",&x2,&y2,&v);
				x1=x2,y1=y2;
				x1++,y1++,x2++,y2++;
				v-=b.sum(x2,y2)-b.sum(x1-1,y2)-b.sum(x2,y1-1)+b.sum(x1-1,y1-1);
				b.update(x2,y2,v);
			}
			else
			{
				scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
				x1++,y1++,x2++,y2++;
				printf("%d\n",b.sum(x2,y2)-b.sum(x1-1,y2)-b.sum(x2,y1-1)+b.sum(x1-1,y1-1));
			}
			scanf("%s",s);
		}
	}
}
