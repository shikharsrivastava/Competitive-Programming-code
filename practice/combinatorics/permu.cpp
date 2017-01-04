#include<bits/stdc++.h>
using namespace std;

void perm(string &s,int p = 0)
{
	if(p==s.length()-1)
	{cout<<s<<endl; return;}
	for(int i=p;i<s.length();i++)
	{
		if(s[i] == s[p] && i!=p) continue;
		swap(s[i],s[p]);
		perm(s,p+1);
		swap(s[i],s[p]);
	}
}

int main()
{
	string s;
	cin>>s;
	perm(s);
}
