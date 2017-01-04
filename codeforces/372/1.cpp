#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
typedef long long int lli;
typedef double db;

int main()
{
	int n,c;
	cin>>n>>c;
	int a[n+1];
	int ans = 1;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[i-1] > c)
		 ans = 1;
		else
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}
