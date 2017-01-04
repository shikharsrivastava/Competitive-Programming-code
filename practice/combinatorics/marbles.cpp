#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long lli;


int main()
{
	int t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>k>>n;
		k = k-n;
		if(k<0)
			cout<<"0\n";
		else
		{
			lli ans = 1;
			for(int i=0;i<k;i++)
			{
				ans *= (n+i);
				ans /= (i+1);
			}
			cout<<ans<<endl;
		}

	}
}
