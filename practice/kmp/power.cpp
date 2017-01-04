//20:50
#include<bits/stdc++.h>
using namespace std;
int main()
{

	string s;
	cin>>s;
	int* z=(int*)calloc(s.length()+1,sizeof(int));

	for(int i=1,l=0,r=0;i<s.length();i++)
	{
		if(i<r)
		z[i]=min(z[i-1],r-z[i]+1);
		while(i+z[i]<s.length() && s[i+z[i]] ==s[z[i]])
		++z[i];
		if(i+z[i]-1>r)
		l=0,r=i+z[i]-1;
	}
	
	for(int i=1;i<s.length();i++)
	{
	
	if(i+z[i]==s.length())
	{
		printf("%d\n",s.length()/i);
		return 0;
	}
	}
	printf("1\n");
}
