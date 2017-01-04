//14:22
#include<bits/stdc++.h>
using namespace std;
void calz(int *z,int n,string s)
{
	for(int i=1,l=0,r=0;i<n;i++)
	{
		if(i<r)
		z[i]=min(z[i-l],r-i+1);
		while(i+z[i]<n && s[z[i]] == s[i+z[i]])
		++z[i];
		if(i+z[i]-1>r)
		l=i,r=i+z[i]-1;
	}
}
int main()
{
	
	int n,len,m=0;
	string s;
	cin>>n;
	while(n!= -1)
	{
	m=0;
	cin>>s;
	len=s.size();
	int *z=(int*)calloc(len+1,sizeof(int));
	calz(z,len,s);
	
	if(n<len)
	printf("0\n");
	else
	{
		for(int i=1;i<len;i++)
		{
			if(i+z[i]==len)
			m=max(m,z[i]);
		}
	printf("%d\n",(n-m)/(len-m));
	}
	free(z);
	cin>>n;
	}
	cin>>s;
	
}

