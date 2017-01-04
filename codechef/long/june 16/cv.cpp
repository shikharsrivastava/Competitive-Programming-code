#include<bits/stdc++.h>
using namespace std;
#define point pair<float,float>
#define y first
#define x second
#define dist(a,b) ((a.y - b.y) * (a.y - b.y) + (a.x - b.x) * (a.x - b.x)) 
#define mp(a,b) make_pair(a,b)

point po;
int orient(point a , point b , point c)
{
	 int area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (area > 0)
        return -1;
    else if (area < 0)
        return 1;
    return 0;
}

bool comp(const point &a , const point &b)	
{
	int order = orient(po, a, b);
    if (order == 0)
        return dist(po, a) < dist(po, b);
    return (order == -1);
}
point ntp(stack<point> &s)
{
	point p = s.top();
	s.pop();
	point ret = s.top();
	s.push(p);
	return ret;
}
void convexHull(vector<point> &p,vector<point> &ans)
{
	int n = p.size();
	if(n<3)
	return;
	
	int ymin = p[0].y;
	int pos = 0;
	for(int i=1;i<n;i++)
	{
		int yp = p[i].y;
		if((yp < ymin) || (yp == ymin && p[i].x<p[pos].x))
		ymin = yp , pos = i;
	}
	
	swap(p[0],p[pos]);
	point po = p[0];
	vector<point>::iterator it = p.begin()+1;
	sort(it,p.end(),comp);
	int m = 1;
	for(int i=1;i<n;i++)
	{
		while(i < n-1 && orient(po,p[i],p[i+1]) == 0)
		i++;
		p[m] = p[i];
		m++;
	}
	
	if(m<3)
	return;

	stack <point> s;
	s.push(p[0]);
	s.push(p[1]);
	s.push(p[2]);
	
	for(int i=3;i<m;i++)
	{
		while(orient(ntp(s),s.top(),p[i]) !=2)
		s.pop();
		s.push(p[i]);
	}
	while(!s.empty())
	{
		point pt = s.top();
		ans.push_back(pt);
		s.pop();
	}
}
float area(vector<point> &p)
{
	float area = 0.0;
	int prev = p.size()-1;
	for(int i=0;i<p.size();i++)
	{
		area +=(p[prev].x+p[i].x) * (p[prev].y - p[i].y);
		prev = i;
	}
	return abs(area/2.0);
}

int main()
{
	vector<point> p;
	vector<point> ans;
	vector<point> allp;
	int n,xc,yc,t;
	char c;
	bool flag;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans.clear();
		p.clear();
		allp.clear();
		ans.clear();
		for(int cas = 1 ;cas <=n ;cas++)
		{
			printf("Case %d\n",cas);
			flag = false;
			scanf(" %c %d %d",&c,&xc,&yc);
			point pt = mp(float(yc),float(xc));
			if(c=='+')
			{
				for(int i=0;i<allp.size();i++)
				{if(allp[i] == pt){flag = true;break;}}
				allp.push_back(pt);
				if(!flag)
				p.push_back(mp(float(yc),float(xc)));
				ans.clear();
				convexHull(p,ans);
				printf("%0.1f\n",area(ans));
			}
			else
			{
				int cnt = 0;
				int pos;	
				for(int i=0;i<allp.size();i++)
				{if(allp[i] == pt){pos = i;cnt++;}}
				allp.erase(allp.begin()+pos);
				if(cnt == 1)
				{
					for(int i=0;i<p.size();i++)
					{if(p[i] == pt){pos = i;break;}}
					p.erase(p.begin()+pos);
				}				
				ans.clear();
				convexHull(p,ans);
				printf("%0.1f\n",area(ans));
			}
		}
	}
	return 0;
}
