//15:14
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k;
	string s;
	cin>>k;
	cin>>s;
	vector<int> b(1),a,pos(1);
	int c=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='1')
		{
		pos.push_back(i);
		b.push_back(c);
		a.push_back(c);
		c=0;
		}
		else
		c++;
	}
	a.push_back(c);
	int ans=0;
	if(k<=pos.size()-1)
	{
	for(int i=1;i<pos.size()-k+1;i++)
	ans+=(b[i]+1)*(a[i+k-1]+1);
	}

	printf("%d\n",ans);
}
