#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;

int main()
{
	lli l,r;
	cin>>l>>r;
	if(l == r)
	{
		cout<<"0"<<endl;
		return 0;
	}

	int i;
	for(i=63;i>=0;i--)
	if(((l>>i)&1) ^ ((r>>i)&1))
	break;

	cout << ((lli)1<<(i+1))-1<<endl;
	
}
