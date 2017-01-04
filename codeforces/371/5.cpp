#include<bits/stdc++.h>

using namespace std;


int main()
{
	int n;
	cin>>n;
	int a[n+1],b[n+1],s[n+1];
	for(int i=1;i<=n;i++)
		{cin>>a[i]; s[i] = a[i];}
	
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++)
	{
		int b[1] = s[i];
		int ans = abs(a[1]-s[i]);
		for(int j=2;j<=n;j++)
		{
			b[i] = a[i]-
		}
	}
}
