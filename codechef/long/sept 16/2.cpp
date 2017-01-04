#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	string s;
	cin>>t;
	while(t--)
	{
		bool f = true;
		cin>>s;
		for(int i=0,j=s.length()-1;i<=j;i++,j--)
		{
			if(s[i] == s[j] && s[i] != '.')
				continue;
			else if(s[i] == s[j] && s[i] == '.')
				s[i] = s[j] = 'a';
			else if(s[i] == '.')
				s[i] = s[j];
			else if(s[j] == '.')
				s[j] = s[i];
			else
			{f =false;break;}
		}
		if(f)
			cout<<s<<endl;
		else
			cout<<"-1\n";		
	}
}
