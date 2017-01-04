//13:55
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1,s2,s;
	cin>>s;
	s1="heavy#"+s;
	s2="metal#"+s;

	int *z1=(int*)calloc(s1.length()+1,sizeof(int));
	int *z2=(int*)calloc(s2.length()+1,sizeof(int));
	int *a=(int*)calloc(s1.length()+1,sizeof(int));

	for(int i=1,l=0,r=0;i<=s1.length();i++)
	{
		if(i<r)
		z1[i]=min(r-i+1,z1[i-l]);
		while(i+z1[i]<s1.length() && s1[i+z1[i]]==s1[z1[i]])
		++z1[i];
		if(i+z1[i]-1>r)
		l=i,r=i+z1[i]-1;
	
	}

	for(int i=1,l=0,r=0;i<=s2.length();i++)
	{
		if(i<r)
		z2[i]=min(r-i+1,z2[i-l]);
		while(z2[i]+i<s2.length() && s2[z2[i]] == s2[i+z2[i]])
		++z2[i];
		if(i+z2[i]-1>r)
		l=i,r=i+z2[i]-1;
	}

	for(int i=0;i<s1.length();i++)
	{
		if(z1[i]==5)
		a[i]=1;
		if(z2[i]==5)
		a[i]=-1;
	}


	long long int ans=0,c=0;
	for(int i=6;i<s1.length();i++)
	{
		if(a[i]==1)
		c++;
		if(a[i]==-1)
		ans+=c;
	}

	printf("%lld\n",ans);
}
