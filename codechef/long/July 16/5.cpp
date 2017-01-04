//14:29
#include<bits/stdc++.h>
using namespace std;
#define N 1005
#define pb push_back



int main()
{
	int t,n,l,r,sz,subarr,ans,inspos;
	int a[N],d[N],to[N];
	set<int> onepos;
	set<int>::iterator itb,ite;
	vector<vector<int> > pos(N+1);
	scanf("%d",&t);
	while(t--)
	{
		ans = 0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			{scanf("%d",&a[i]); d[i] = a[i];pos[i].clear();}

		sort(d+1,d+n+1);
		int size = unique(d+1,d+n+1) - (d+1);
		
		for(int i=1;i<=n;i++)
			to[i] = lower_bound(d+1,d+size+1,a[i]) - d;
		for(int i=1;i<=n;i++)
			pos[to[i]].pb(i);
				
	
		for(int s=1;s<n;s++)
		{
			onepos.clear();
			sz = n-s+1;
			subarr = (sz*(sz+1))/2;
			for(int e=s;e<n;e++)
			{
				if(onepos.find(e) == onepos.end()) 
				{
					for(int i=pos[to[e]].size()-1;i>=0;i--)
					{
						inspos = pos[to[e]][i];
						if(inspos < e) break;
						itb = onepos.lower_bound(inspos);
						if(itb == onepos.begin())
						l = e-1;
						else
						ite = itb , l = *(--ite);
						if(itb == onepos.end())
						r = n+1;
						else
						r = *itb;
						subarr -= ((r-l-1)*(r-l))/2;
						subarr += ((inspos-l-1)*(inspos-l))/2;
						subarr += ((r-inspos-1)*(r-inspos))/2;
						onepos.insert(inspos);
					}
				}
				ans += subarr;
			}
		}
		printf("%d\n",ans);
	}
}
