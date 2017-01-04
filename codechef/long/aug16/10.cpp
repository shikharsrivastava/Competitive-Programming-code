#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long int lli;
struct point
{
	int x;
	int y;
} house;

struct Vector
{
	lli i,j,k;
	Vector(lli I,lli J,lli K)
	{
		i = I, j=J , k= K;
	}
	Vector operator*(const Vector b)
	{
		lli I = j*b.k - k*b.j;
		lli J = k*b.i - i*b.k;
		lli K = i*b.j - j*b.i;
		return Vector(I,J,K);
	}
};

bool inside(point a,point b,point c)
{
	Vector ab(b.x-a.x,b.y-a.y,0);
	Vector bc(c.x-b.x,c.y-b.y,0);
	Vector ca(a.x-c.x,a.y-c.y,0);
	Vector ap(house.x-a.x,house.y-a.y,0);
	Vector bp(house.x-b.x,house.y-b.y,0);
	Vector cp(house.x-c.x,house.y-c.y,0);
	Vector abap = ab*ap;
	Vector bcbp = bc*bp;
	Vector cacp = ca*cp;
	
	if((abap.k <0) && (bcbp.k <0) && (cacp.k <0))
	return true;
	else if ((abap.k >0) && (bcbp.k >0) && (cacp.k >0))
	return true;
	else
	return false;
	
}

int main()
{
	house.x = house.y = 0;
	int n;
	lli ans = 0;

	scanf("%d",&n);
	point p[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&p[i].x,&p[i].y);
		if(i > 2)
		{
			for(int p1=1;p1<i;p1++)
			{
				for(int p2 = p1+1;p2<i;p2++)
				if(inside(p[p1],p[p2],p[i]))
					ans++;
				
			}	
		}
		printf("%lld\n",ans);
		fflush(stdout);
	}
}
