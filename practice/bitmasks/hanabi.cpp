//14:06
/*
	Bitmasks to make group of elements which have same set of hints pointing towards them
	All elements in such groups should be equal to correctly identify the order
	Also using brute force bitmasks to generate all combination of hints and printing the minimum that can find answer 
*/
#include<bits/stdc++.h>
using namespace std;
int n,hs[101];
string s[101];
void clearhints()
{
	for(int i=1;i<=n;i++)
		hs[i] = 0;
}
void sethint(int b)
{
	if(b<5)
	{
		for(int i=1;i<=n;i++)
			if(s[i][1] - '1' == b)
				hs[i] |= 1<<b;
	}
	else
	{
		for(int i=1;i<=n;i++)
			if(s[i][0] - 'A' == b-5)
				hs[i] |= 1<<b;
	}
}

bool canfind()
{
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if (hs[i] == hs[j] && s[i] != s[j])
				return false;
	return true;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[i][0] == 'R')
			s[i][0] = 'A';
		else if(s[i][0] == 'G')
			s[i][0] = 'B';
		else if(s[i][0] == 'B')
			s[i][0] = 'C';
		else if(s[i][0] == 'Y')
			s[i][0] = 'D';
		else if(s[i][0] == 'W')
			s[i][0] = 'E';
			
	}
	int ans = 100000;

	for(int i=0;i<1<<10;i++)
	{
		clearhints();
		for(int j=0;j<10;j++)
			if((i>>j) &1)
				sethint(j);
		if(canfind())
			ans = min(ans,__builtin_popcount(i));
	}
	cout<<ans<<endl;
}
