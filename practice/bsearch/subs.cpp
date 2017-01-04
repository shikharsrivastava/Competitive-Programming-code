/*
	Simple binary search to find the maximum number from possibe valus i,e [1,len(b)/len(a)]
	By using boolean function that tells if string a to power m is subsequence of string b 
*/
#include<bits/stdc++.h>
using namespace std;

bool issubs(char *a,char *b,int m)
{
	int lb=strlen(b);
	int la=strlen(a);
	int c=0,j=0;
	if(m==0)
	return true;
	if(lb<la)
	return false;
	for(int i=0;i<lb;i++)
	{
		if(b[i]==a[j])
		c++;
		if(c==m)
		c=0,j+=1;
		if(j==la)
		return true;
		if((la-j)*m-c > (lb-i))
		return false;
	}
}

int main()
{
	int t,m,s,e,md;
	char a[500011],b[500011];
	scanf("%d",&t);
	while(t--)
	{
	scanf("%s %s",a,b);
	m=strlen(b)/strlen(a);
	s=1,e=m;
	while(s<e)
	{
		md=(s+e)/2;
		if(issubs(a,b,md))
			s=md+1;
		else
			e=md-1;
			
	}
	if(!issubs(a,b,s))
	printf("%d\n",s-1);
	else
	printf("%d\n",s);

	}
}
