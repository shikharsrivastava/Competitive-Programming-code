#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
typedef long long int lli;
typedef double db;
using namespace std;

int a[5];
int main()
{
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i] == 'U')
			a[1]++;
		else if(s[i] == 'D')
			a[2]++;
		else if(s[i] == 'R')
			a[3]++;
		else
			a[4]++;
	}
	int diff1 = abs(a[1]-a[2]);
	int diff2 = abs(a[3]-a[4]);
	if(diff1 == diff2)
		printf("%d\n",diff1);
	else
		printf("-1\n");
}
