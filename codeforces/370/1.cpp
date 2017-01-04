#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
typedef long long int lli;
typedef double db;
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[n+2];
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		a[n+1] = 0;
	vector<int> ans;
	for(int i=n;i>=1;i--)
		ans.pb(a[i]+a[i+1]);
	for(int i=ans.size()-1;i>=0;i--)
		printf("%d ",ans[i]);
	printf("\n");
}
