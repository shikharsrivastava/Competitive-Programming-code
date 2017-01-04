//14:59
#include<bits/stdc++.h>
using namespace std;
int s;
void update1d(int *b,int p,int v)
{
	while(p<=s)
	{
	b[p]+=v;
	p+=p&-p;
	}
}
int sum1d(int *b,int p)
{
	int ans=0;
	while(p>0)
	{
		ans+=b[p];
		p-=p&-p;
	}
	return ans;
}

void update2d(int **b,int x,int y,int v)
{
	while(x<=s)
	{
		update1d(b[x],y,v);
		x+=x&-x;
	}
}
int sum2d(int** b,int x,int y)
{
	int ans=0;
	while(x>0)
	{
		ans+=sum1d(b[x],y);
		x-=x&-x;
	}
	return ans;
}

int main()
{
	int **bit,c,x,y,a,l,b,r,t;
	s=1;
	bit=(int**)calloc(s+1,sizeof(int*));
	for(int i=0;i<=s;i++)
	bit[i]=(int*)calloc(s+1,sizeof(int));
	scanf("%d",&c);
	while(c != 3)
	{

		switch(c)
		{
		case 0: for(int i=0;i<=s;i++)
			free(bit[i]);
			free(bit);
			scanf("%d",&s);
			bit=(int**)calloc(s+1,sizeof(int*));
			for(int i=0;i<=s;i++)
			bit[i]=(int*)calloc(s+1,sizeof(int));
			break;
		case 1: scanf("%d %d %d",&x,&y,&a);
			x++,y++;
			update2d(bit,x,y,a);
			break;
		case 2: scanf("%d %d %d %d",&l,&b,&r,&t);
			l++,b++,r++,t++;
			printf("%d\n",sum2d(bit,r,t)-sum2d(bit,l-1,t)-sum2d(bit,r,b-1)+sum2d(bit,l-1,b-1));
			break;
		}
	scanf("%d",&c);
	}
	
}
