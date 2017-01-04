/*
	Very good Question on DSU
*/

#include<bits/stdc++.h>
using namespace std;

struct st
{
	int parent;
	int link;
} s[50001];

int find(int x)
{
	if(s[x].parent == x)
	return x;
		
	int prevp = s[x].parent;
	s[x].parent = find(s[x].parent);
	s[x].link += s[prevp].link;
	return s[x].parent;
}

int main()
{
	int t,n,m,ans,x,y,c;
	scanf("%d",&t);
	while(t--)
	{
		ans = 0;
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++)
		s[i].parent = i , s[i].link = 0;

		for(int i=1;i<=m;i++)
		{
			scanf("%d %d %d",&c,&x,&y)
			if(x>n || y>n) {ans++;continue;}
			int px = find(x);
			int py = find(y);
	
			if(c == 1)
			{
				int diff = (s[y].link - s[x].link) % 3;
				diff < 0 ? (diff+=3) : diff;
				if(px != py)
				{
					if(diff == 1)
					s[px].link +=  1;
					else if(diff == 2)
					s[px].link -= 1;
					s[px].parent = py;
				}
				else if(diff != 0)
				ans++;				
			}
			else
			{
				if(x == y) {ans++ ; continue;}
				int diff = (s[y].link + 1 - s[x].link) % 3;
				diff < 0 ? (diff+=3) : diff;	

				if(px != py)
				{
					if(diff == 1)
					s[px].link +=  1;
					else if(diff == 2)
					s[px].link -= 1;
					s[px].parent = py;
				}
				else
				{
					int md = (s[x].link - s[y].link)%3;
					md < 0 ? (md+=3) : md;
					printf("md = %d\n",md);
					if(md != 1)
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
}
