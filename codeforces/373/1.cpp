#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

typedef long long lli;
typedef double db;


int main()
{
	int n;
	cin>>n;
	int a[n+1];

	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(a[n] == 0)
		printf("UP\n");
	else if(a[n] == 15)
		printf("DOWN\n");
	else if(n == 1)
		printf("-1\n");
	else if(a[n]-a[n-1] >0)
		printf("UP\n");
	else if(a[n]-a[n-1] <0)
		printf("DOWN\n");
	
		
	return 0;
}
