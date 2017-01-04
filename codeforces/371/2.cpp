#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define pb push_back
int main()
{
	int n;
	cin>>n;
	set<int> a;
	vector<int> ans;
	int arr[n+1];
	for(int i=1;i<=n;i++)
	{cin>>arr[i];a.insert(arr[i]);}
	if(a.size() >3)
		cout<<"NO\n";
	
	else
	{
		for(set<int>::iterator it = a.begin(); it != a.end();it++)
			ans.pb(*it);

		if(a.size() == 1)
			cout<<"YES\n";
		else if(a.size() == 2)
			cout<<"YES\n";
		else
		{
			if(ans[1]-ans[0] == ans[2]-ans[1])
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
	}
}
