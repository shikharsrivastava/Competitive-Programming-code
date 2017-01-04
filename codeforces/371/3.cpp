#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
int pattern(lli num)
{
	int ret = 0;
	int i = 0;
	while(num>0)
	{
		int c = num%10;
		if(c%2 == 1)
			ret |= (1<<i);
		i++;
		num /= 10;
			
	}
	return ret;
}

int hash[1<<20];
int main()
{
	int t;
	cin>>t;
	char c;
	lli num;
	while(t--)
	{
		cin>>c>>num;
		int patt = pattern(num);
		
		if(c=='+')
			hash[patt]++;
		else if(c == '-')
			hash[patt]--;
		else
			cout<<hash[patt]<<endl;		
	}
}
