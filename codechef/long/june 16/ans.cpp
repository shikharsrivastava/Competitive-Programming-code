#include<bits/stdc++.h>
using namespace std;
#define dist(a,b) ((a.y-b.y)*(a.y-b.y) + (a.x-b.x)*(a.x-b.x)) 
struct coord{
public:
    float x, y;

    bool operator < (coord b) {
        if (y != b.y)
            return y < b.y;
        return x < b.x;
    }
};


coord po;

int orient(coord a, coord b, coord c) {
    float area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (area > 0)
        return -1;
    else if (area < 0)
        return 1;
    return 0;
}



bool cmp(coord a, coord b)  {
    int od = orient(po, a, b);
    if (od == 0)
        return dist(po, a) < dist(po, b);
    return (od == -1);
}

void convexHull(vector<coord> &p, vector<coord> &ans) 
{
    stack<coord> s;
    int n = p.size();
    if (n < 3)
        return;

    int miny = 0;
    for (int i = 1; i < n; i++)
        if (p[i] < p[miny])
            miny = i;

    swap(p[0],p[miny]);

    po = p[0];
    sort(p.begin() + 1, p.end(), cmp);

    s.push(p[0]);
    s.push(p[1]);
    s.push(p[2]);

    for (int i = 3; i < n; i++) {
        coord top = s.top();
        s.pop();
        while (orient(s.top(), top, p[i]) != -1)   {
            top = s.top();
            s.pop();
        }
        s.push(top);
        s.push(p[i]);
    }
    while(!s.empty())
	{
		coord p = s.top();
		s.pop();
		ans.push_back(p);
	}
	return;
}

double area(vector<coord> &p)
{
	double area = 0.0;
	int prev = p.size()-1;
	for(int i=0;i<p.size();i++)
	{
		area +=(double)(p[prev].x+p[i].x) * (p[prev].y - p[i].y);
		prev = i;
	}
	return abs(area/2.0);
}

int main()
{
	vector<coord> p;
	vector<coord> ans;
	int n,t,cnt,pos;
	coord pt;
	float xc,yc;
	char c;
	bool flag;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans.clear();
		p.clear();
		while(n--)
		{
			flag = false;
			scanf(" %c %f %f",&c,&xc,&yc);
			pt.x = xc , pt.y = yc;
			if(c=='+')
				p.push_back(pt);
			
			else
			{	
				for(int i=0;i<p.size();i++)
				{
					if(p[i].x == pt.x && p[i].y == pt.y)
					{p.erase(p.begin()+i);break;}
				
				}
			}
			ans.clear();
			convexHull(p,ans);
			printf("%0.1lf\n",area(ans));
		}
	}
	return 0;
}
