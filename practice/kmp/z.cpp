#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,l,r;
	printf("enter the string\n");
	char s[100];
	scanf("%s",s);
	n=strlen(s);
	
	vector<int> z(n);
	for(int i=1,l=0,r=0;i<n;i++)
	{
		if(i<r)
		z[i]=min(z[i-l],r-i+1);
		while(i+z[i]<n && s[z[i]]==s[i+z[i]])
		++z[i];
		if(i+z[i]-1>r)
		l=i,r=i+z[i]-1;
	}

	for(int i=0;i<=n;i++)
	printf("%d ",z[i]);
	printf("\n");
}
