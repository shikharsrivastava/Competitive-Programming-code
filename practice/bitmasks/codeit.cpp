#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main()
{
	vector<vector<int > > sets(21);
	for(int i=1;i<(1<<20);i++)
	{
		int c = __builtin_popcount(i);
		sets[c].pb(i);
	}
	int t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		int a[n+1];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int fans = 0;
		for(int i=0,c=0,ans=0;i<sets[k].size();i++,c=0,ans=0)
		{
			if(sets[k][i] >= (1<<n))
				break;
			for(int b=0;b<n;b++)
				if((sets[k][i]>>b) &1)
					c++;
			if(c<k) continue;
		
			for(int b=0;b<n;b++)
				if((sets[k][i]>>b) &1)
					ans ^= a[b];
			fans = max(fans,ans);	
		}
		cout<<fans<<endl;
	}
	return 0;
}
