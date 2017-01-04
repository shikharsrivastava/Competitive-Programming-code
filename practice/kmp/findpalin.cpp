//21:50
/*
	Simple question 
	Find period of all strings, Since all strings are plaindromes , the strings with same periods will be palindromes if concat
	Group all such strings together and with combinatorics find the answer
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int calz(char *s,int n)
{
	int *z=(int*)calloc(n+1,sizeof(int));
	for(int i=1,l=0,r=0;i<n;i++)
	{
	if(i<r)
	z[i]=min(z[i-l],r-i+1);
		while(i+z[i]<n && s[i+z[i]]==s[z[i]])
		++z[i];

		if(i+z[i]-1>r)
		l=i,r=i+z[i]-r;

		if(i+z[i]==n)
		{
		if(n%i==0)
		{
		free(z);	
		return i;
		}
		}	
	}
	free(z);
	return n;
}

string substr(char *pat ,int len)
{
	string s="";
	for(int i=1;i<=len;i++)
	s+=pat[i-1];
	return s;
}

bool equals(string s1 ,string s2)
{
	if(s1.length() != s2.length())
	return false;
	else
	{
		for(int i=0;i<s1.length();i++)
		if(s1[i] !=s2[i])
			return false;
		return true;
	}
}
int main()
{
	int n,len,temp;
	scanf("%d",&n);
	char pat[2000001];
	vector<string> v(n);
	for(int i=0;i<n;i++)
	{
	scanf("%d%s",&len,pat);
	len=calz(pat,len);
	v[i]=substr(pat,len);	
	}

	sort(v.begin(),v.end());
	

	long long int ans=0;
	for(int i=0;i<v.size();i++)
	{
		temp=1;
		while(i<v.size()-1 && equals(v[i],v[i+1]))
		temp++,i++;
		ans+=(ll)temp*temp;
	}

	printf("%lld\n",ans);
	
	
}
