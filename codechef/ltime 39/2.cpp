#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
#define pib pair<int,int>
int n;
vector<vector<pib> > thno(1001);
int ptr[100001];
int arr[1000001];
bool findans(int id)
{
	if(id <1)
		return true;

	bool f = false;
	for(int i=0;i<thno[arr[id]].size();i++)
		{	
			int num = arr[id];
			if(ptr[thno[num][i].first] == thno[num][i].second)
				{
					ptr[thno[num][i].first]++;
					f = f| findans(id-1);
					ptr[thno[num][i].first]--;
					if(f)
						return true;
				}
		}
		return f;
}
int main()
{
	int t,c,num,total = 0;
	scanf("%d",&t);
	for(int i=0;i<=100000;i++)
		ptr[i] = 1;
	while(t--)
	{
		for(int i=0;i<=1000;i++)
			thno[i].clear();

		total = 0;
		scanf("%d",&n);
		if(n == 1)
		{
			
			scanf("%d",&c);
			int a[c+1];		
			for(int i=1;i<=c;i++)
				scanf("%d",&a[i]);
			for(int i=1;i<=c;i++)
				scanf("%d",&arr[i]);
			bool f = true;
			for(int i=1;i<=c;i++)
				if(a[i] != arr[c-i+1])
					{f = false;break;}
			if(f)
				printf("Yes\n");
			else
				printf("No\n");
			
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				scanf("%d",&c);
				total += c;
				for(int j=1;j<=c;j++)
					{scanf("%d",&num);thno[num].pb(mp(i,j));}
			}
				for(int i=1;i<=total;i++)
					scanf("%d",&arr[i]);
				if(findans(total))
					printf("Yes\n");
				else
					printf("No\n");
		}
		
			
	}
}
