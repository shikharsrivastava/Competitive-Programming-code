//20:19
#include<bits/stdc++.h>
using namespace std;

int main()
{

	int n;
	cin>>n;
	string s="abcd";
	for(int i=1;i<=n/4;i++)
	cout<<s;

	for(int i=0;i<n%4;i++)
	printf("%c",s[i]);
	printf("\n");
}
