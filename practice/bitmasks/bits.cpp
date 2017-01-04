#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;

lli ans(lli a,lli b)
{
	int bit = 63;
	lli ans = 0;
	for(;bit>=0;bit--)
	{
		if((a>>bit &(lli)1) ^ ((b>>bit)&(lli)1))
		break;
		else
		ans |= ((a>>bit) &(lli)1)<<bit;
	}
	if(bit<0)
	return ans;

	ans += ((lli)1<<(bit))-1;

	if(ans + ((lli)1 <<(bit)) <= b)
	return ans + ((lli)1<<(bit));
	else
	return ans;
}

int main()
{
	lli n,a,b;
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		cout<<ans(a,b)<<endl;
	}
}
