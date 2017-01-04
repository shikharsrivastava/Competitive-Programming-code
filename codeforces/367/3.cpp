//15:54
#include<bits/stdc++.h>
using namespace std;
#define MX 1000000000000000000
typedef  long long int lli;
int main()
{
	
	int n;
	cin>>n;
	lli cost[n+1],scost[n+1],rcost[n+1];
	for(int i=1;i<=n;i++)
	cin>>cost[i];

	string arr[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		scost[i] = rcost[i] = MX;	
	}
	
	scost[1] = 0;
	rcost[1] = cost[1];
	lli ans = 0;
	bool f = false;
	for(int i=1;i<=n;i++)
	{
		string revp = arr[i-1];
		string rev = arr[i];
		reverse(rev.begin(),rev.end());
		reverse(revp.begin(),revp.end());
		if(arr[i] >= arr[i-1])
		scost[i] = min(scost[i],scost[i-1]);
		if(arr[i] >= revp)
		scost[i] = min(scost[i],rcost[i-1]);
		if(rev >= arr[i-1])
		rcost[i] = min(rcost[i],scost[i-1]+cost[i]);
		if(rev >= revp)
		rcost[i] = min(rcost[i],rcost[i-1]+cost[i]);
		ans = min(scost[i],rcost[i]);
		if(ans == 1000000000000000000)
		{f = true;break;}
	}
	if(f)
	cout<<(-1)<<endl;
	else
	cout<<ans<<endl;
	

}
