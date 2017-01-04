//16:21
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int a[5] = {0,2,4,6,8};
int main()
{
	int t;
	lli k;
	vector<int> s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&k);
		if(k == 1)
		printf("0");
		k--;
		s.clear();
		while(k>0)
		{	
			s.push_back(k%5);
			k/=5;	
		}
		reverse(s.begin(),s.end());
		for(int i=0;i<s.size();i++)
		printf("%d",a[s[i]]);
		printf("\n");
	}
}
