//11:55
#include<bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)

int main()
{
	vector<int> xa,xb;
	vector<pair<int,int> > xp;
	vector<vector<int> > m(5000);
	int st[3005];
	int a,b,c,d,arr[4];
	for(int i=0;i<4;i++)
	scanf("%d",&arr[i]);
	sort(arr,arr+4);
	a=arr[0];
	b=arr[1];
	c=arr[2];
	d=arr[3];
	
	for(int i=1;i<=a;i++)
	{	for(int j=i;j<=b;j++)
		{
			xp.push_back(mp(i,j));
			xa.push_back(i^j);
		}
	}	
	for(int i=1;i<=c;i++)
	{
		st[i] = xb.size();	
		for(int j=i;j<=d;j++)
		{
			m[i^j].push_back(xb.size());
			xb.push_back(i^j);
		}
	}
	int n=xb.size()-1;
	long long int fans=0,ans;
	for(int i=0;i<xa.size();i++)
	{
		int s=st[xp[i].second];
		vector<int>::iterator it=lower_bound(m[xa[i]].begin(),m[xa[i]].end(),s);
		if(it == m[xa[i]].end())
		ans=0;
		else
		ans=m[xa[i]].end()-it;
		fans += (n-s+1) -ans;
	}
	printf("%lld\n",fans);
}
