#include<bits/stdc++.h>
int sign(int x)
{
	if(x<0)
	return -1;
	return 1;
}
int main()
{
	int n,s,add,prev,sgn,t;
	scanf("%d",&t);
	
	for(int j=1;j<=t;j++)
	{
	scanf("%d %d",&n,&s);
	if(j>1)
	printf("\n");

	if(abs(n*(n-1)/2)%2 != abs(s)%2 || abs(s)>abs(n*(n-1)/2))
	printf("No\n");

	else
	{	add=prev=0;
		sgn=sign(s);
		printf("0\n");
		for(int i=2;i<=n;i++)
	{
		if(sgn*(add+(2*(prev-(1*sgn))+(n-i)*(sgn))*(n-i+1)/2) >=sgn*s)
		prev-=1*sgn;
		else
		prev+=1*sgn;

		add+=prev;
		printf("%d\n",prev);
	
	}
	}
	
	}	
}
