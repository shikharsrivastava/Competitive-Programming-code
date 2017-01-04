#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
typedef long long int lli;
typedef double db;

int main()
{
	int n;
	cin>>n;
	lli cn = 2;
	for(int i=2;i<=n+1;i++)
	{
		int mul = 1;
		cout<<"muli = "<<mul<<endl;
		while(! (i*i*mul*mul > cn && ((i*i*mul*mul)-cn) % i == 0))
		mul++;
		cout<<"mulf = "<<mul<<endl;
		cout<<(i*i*mul*mul)-cn<<endl;
		cn = i*mul;	
		cout<<"cn = "<<cn<<endl;	
	}
	return 0;
}
