//13:36
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define gc getchar_unlocked
int scanint()
{
    register int c = gc();
    int x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
    return x;
}
char scanchar()
{
 
    register int x = gc();
    for(;(x < 65 || x > 97);x = gc());
    return (char)x;
}
int main()
{
	int n,m,a;
	n = scanint();
	m = scanint();
	unordered_multimap<int,int> lst;
	for(int i=1;i<=n;i++)
	{
		a = scanint();
		lst.insert(mp(a,i));
	}
	char t;
	while(m--)
	{
		t = scanchar();
		if(t == 'S')
		{
			a = scanint();
			auto it = lst.equal_range(a);
			if(it.first != lst.end())
			{
				auto x = it.first;
				auto y = it.first;
				y++;
				while(y != it.second)
				x=y,y++;
				printf("%d\n",x->second);
			}
			else
			printf("NONE\n");
		}
		else if(t == 'I')
		{
			a = scanint();
			n++;
			lst.insert(mp(a,n));
			printf("%d\n",n);
		}
		else
		{
			a = scanint();
			auto it = lst.equal_range(a);
			if(it.first != lst.end())
			{
				auto x = it.first;
				auto y = it.first;
				y++;
				while(y != it.second)
				x=y,y++;
				printf("%d\n",x->second);
				lst.erase(x);
			}
			else
			printf("NONE\n");
		}
	}
}
