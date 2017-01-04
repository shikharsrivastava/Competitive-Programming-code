#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
typedef long long int lli;
typedef double db;
int hash[27];
int fq(string &s, int i)
{
	int ret = 0;
	for(int id = i;id<i+26;id++)
	if(s[id] == '?')
		ret++;
	return ret;
}

int dq(string &s,int i)
{
	memset(hash,0,sizeof(hash));
	for(int id=i;id<i+26;id++)
	if(s[id] != '?')
		hash[s[id]-'A']++;
	int ret = 0;
	for(int id=0;id<26;id++)
	if(hash[id])
		ret++;

	return ret;
	
}

int main()
{
	string s;
	cin>>s;
	if(s.length() < 26)
		cout<<"-1\n";
	else
	{
		bool f = false;
		int ansi = 0;
		for(int i=0;i<=s.length()-26;i++)
		{
			int ques = fq(s,i);
			int diff = dq(s,i);
			if(26-diff == ques)
			{
				f = true;
				ansi = i;

				break;
			}
		}
		if(!f)
			cout<<"-1\n";
		else
		{
			vector<char> v;
			for(int i=0;i<26;i++)
				if(!hash[i])
					v.pb('A'+i);
			int ind = 0;

			for(int i=0;i<ansi;i++)
			if(s[i] == '?')
			cout<<'A';
			else
			cout<<s[i];

			for(int i=ansi;i<ansi+26;i++)
				if(s[i] == '?')
				cout<<v[ind++];
				else
				cout<<s[i];

			for(int i=ansi+26;i<s.length();i++)
			if(s[i] == '?')
			cout<<'A';
			else
			cout<<s[i];
			cout<<endl;		
		}
	}
	return 0;
}
