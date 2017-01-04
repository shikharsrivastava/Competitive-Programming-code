//19:58
#include<bits/stdc++.h>
using namespace std;

struct tree
{
	int x;
	int y;
	int h;
};
int main()
{
	int t,n,x1,x2y1,y2,*x,*y,*sx,*sy,**b,nx,ny;
	tree *t;
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		t=(tree*)calloc(n+1,sizeof(tree));
		x=(int*)calloc(n+1,sizeof(int));
		y=(int*)calloc(n+1,sizeof(int));
		sx=(int*)calloc(n+1,sizeof(int));
		sy=(int*)calloc(n+1,sizeof(int));
		
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&t[i].x,&t[i].y,&t[i].h);
			x[i]=t[i].x;
			y[i]=t[i].y		
		}	
		sort(x+1,x+n+1);
		sort(y+1,y+n+1);
		
		nx=ny=0;
		for(int i=1;i<=n;i++)
		{
		tmp=x[i];
		while(i<=n && x[i]==tmp)
		sx[++nx]=a[i],i+=1;	
		}
		for(int i=1;i<=n;i++)
		{
		tmp=y[i];
		while(i<=n && y[i]==tmp)
		sy[++nx]=a[i],i+=1;	
		}
	
		bit=(int**)calloc(sx+1,sizeof(int*));;
		for(int i=0;i<=sx;i++)
		bit[i]=(int*)calloc(sy+1,sizeof(int));
		
	}
}
