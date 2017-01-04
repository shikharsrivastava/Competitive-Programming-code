//18:05
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int  n;
int dp[76][151];
int d[151];
vector<int> mp[27];
int findsub(string s,string ps,int st,int e)
{

	for(int i=0;i<=26;i++)
		mp[i].clear();
	for(int i=st,j=1;i<=e;i++,j++)
		mp[ps[i] - 'A'].pb(j);
	memset(d,0,sizeof(d));
	d[0] = 1;
	for(int i=0,j=1;i<s.length();i++)
	{
		if(mp[s[i]-'a'].empty()) continue;
		int index = s[i]-'a';
		for(int ind=mp[index].size()-1;ind>=0;ind--)
		{
			if(mp[index][ind] >j) continue;
			d[mp[index][ind]] += d[mp[index][ind]-1];
		}
		j++;
		 
	}

	return d[e-st+1];

}
int getans(string *s,int l)
{	
	memset(dp,0,sizeof(dp));
	int len = s[0].length();
	dp[l+1][len] = 1;
	for(int i=l;i>0;i--)
	{
		for(int st=i-1;st<len-(l-i);st++)
		for(int en=st;en<len-(l-i);en++)
		{
			int ans = findsub(s[i],s[0],st,en);
			if(ans == 0) break;
			dp[i][st] += ans*dp[i+1][en+1];
		}
	}

	return dp[1][0];
}
int main()
{
	string inp[200];	
	set<string> insig;
	string str;
	while(1)
	{	
		insig.clear();
		cin>>n;
		if(n == 0) break;
		for(int i=1;i<=n;i++)
			{cin>>str;insig.insert(str);}
		cin>>inp[0];
		while(1)
		{
			cin>>inp[1];

			if(inp[0] == "LAST" && inp[1] == "CASE") break;
			int l = 1;
			while(inp[l][0] >= 'a' && inp[l][0] <= 'z')
				{if(insig.find(inp[l]) != insig.end()) l--; cin>>inp[++l];}
			l--;
			
			int ans = getans(inp,l);
			if(ans)
			cout<<inp[0]<<" can be formed in "<<ans<<" ways\n";	
			else
			cout<<inp[0]<<" is not a valid abbreviation\n";
			inp[0] = inp[l+1];
		}	
	}

	
	
	
}
