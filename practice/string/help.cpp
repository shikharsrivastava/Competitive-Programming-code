//15:36
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int pos,flag=20;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='.')
		{
			pos=i-1;
			break;
		}
	}

	if(s[pos]=='9')
	printf("GOTO Vasilisa.");
	else
	{
		int i=pos+2;
		if(s[i]>'5')
			s[pos]+=1;
		else if(s[i]=='5')
		{
		i++;
		flag=0;
		while(i<s.length())
		{
			if(s[i]> '0')
			{
			s[pos]+=1;
			flag=1;
			break;
			}
		i++;
		}
		}
		if(flag==0)
		s[pos]+=1;
		for(int i=0;i<=pos;i++)
		printf("%c",s[i]);
		
	}
	printf("\n");
}
