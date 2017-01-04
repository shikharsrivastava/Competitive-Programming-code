#include<bits/stdc++.h>
using namespace std;
typedef double db;

db integrate(int h,int k,int r,int x)
{
	db a0 = a*a - (h-x)*(h-x);

	db a1 = sqrt(a*a - (h-x)*(h-x)) * (h-x);
	db area = 0.5 * wtan(a1 / ((h-x)*(h-x) - a*a))*a*a - 0.5 * a1 + k * x;
	return area;
}

db area(int h,int k,int r,int x1,int x2)
{
	db f = integrate(h,k,r,x1);
	db s = integrate(h,k,r,x2);
	return s-f;
}

struct circle
{
	int x;
	int y;
	int r;
} points[100005];
int x1,y2,x2,y2;

bool intersect(int i)
{
	
}
int main()
{
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&q);
		for(int i=1;i<=n;i++)	
			scanf("%d %d %d",&points[i].x,&points[i].y,&points[i].r);
		sort(points+1,points+n+1);
		dd ans =  0;
		while(q--)
		{
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			for(int i=1;i<=n;i++)
			{
				if(inside(x1,y1,x2,y))
			}
		}
		
	}
	
}
