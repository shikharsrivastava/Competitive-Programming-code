#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
pair<pair<int,int> ,int> e[1001];
int main()
{
	int n,m,k,u,v,w,a,b;
	scanf("%d %d %d",&n,&m,&k);
	
	scanf("%d %d",&a,&b);
	if(n>10) return 0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		e[i].first.first = u;
		e[i].first.second = v;
		e[i].second = w;
	}
	vector<int> ans;
	for(int mask=1;mask<1<<n;mask++)
	{
		int sum = 0;
		if((mask>>(a-1))&1 && !((mask>>(b-1))&1))
		{
			for(int j=1;j<=m;j++)
			{
				u = e[j].first.first;
				v = e[j].first.second;
				w = e[j].second;

				if(((mask>>(u-1))&1) && !((mask>>(v-1))&1))
					sum +=w;
			}
			ans.pb(sum);
		}
		
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans[k-1]);
	return 0;
}
