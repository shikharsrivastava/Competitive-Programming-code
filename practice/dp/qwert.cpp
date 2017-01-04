//21:26
#include<bits/stdc++.h>
using namespace std;
int mem[101][101];
string s;
int n;
int dp(int i,int reg)
{
	if(i == n-1)
	{
		if(s[i] == '1' && reg!=0)
			return 1;
		else if(s[i] == '1' && reg == 0)
			return 2;
		else if(s[i] == '0' && reg != 3)
			return 1;
		else
			return 2; 
	}
	int ret = 10000000;
	if(mem[i][reg] != -1)
		return mem[i][reg];
	
	if(s[i] == '1' && reg !=0)
		ret = min(ret,1+dp(i+1,reg));
	if(s[i] == '1' && reg == 0)
		{
			ret = min(ret,2+dp(i+1,reg | (1<<1)));
			ret = min(ret,2+dp(i+1,reg | (1<<0)));
			ret = min(ret,2+dp(i+1,~reg));
		}
	if(s[i] == '0' && reg == 3)
	{
		ret = min(ret,2+dp(i+1,1));
		ret = min(ret,2+dp(i+1,2));
		ret = min(ret,2+dp(i+1,0));
	}
	if(s[i] == '0' && reg != 3)
		ret = min(ret,1+dp(i+1,reg));
	int num = ((s[i]-'0')<<1) | (s[i+1]-'0');
	if(num == reg)
		ret = min(ret,1+dp(i+2,reg));
	else if(num == ~reg)
		ret = min(ret,2+dp(i+2,~reg));
	mem[i][reg] = ret;
	return ret;
	
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(mem,-1,sizeof(mem));
		cin>>s;
		n = s.length();
		cout<<dp(0,0)<<endl;
	}
}
