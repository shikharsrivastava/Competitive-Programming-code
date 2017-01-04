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
	int n,ans = 1000000000;
	scanf("%d",&n);
	char s[n+1];
	scanf("%s",s);
	// start with b
	int a[n+1];
	for(int i=0;i<n;i++)
	if(s[i] == 'r')
		a[i] = 1;
	else
		a[i] = 0;
	
	int num = 1,one = 0,zero = 0;
	for(int i=0;i<n;i++)
	{
		if(a[i] == 1 && a[i] != num)
			one++;
		else if(a[i] == 0 && a[i] != num)
			zero++;
		num ^=1;
	}
	int mn = min(one,zero);
	ans = min(ans,mn+one+zero-2*mn);
	// starting with zero
	num = 0,one =0,zero = 0;
	for(int i=0;i<n;i++)
	{
		if(a[i] == 1 && a[i] != num)
			one++;
		else if(a[i] == 0 && a[i] != num)
			zero++;
		num ^=1;
	}
	mn = min(one,zero);
	ans=  min(ans,mn+one+zero-2*mn);
	printf("%d\n",ans);
	return 0;
}
