#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define mp make_pair
#define pb push_back


int main()
{
	int n;
	scanf("%d",&n);
	char s[n+1];
	int a[n+1];
	scanf("%s",&s[1]);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	
	int dist = INF;
	int prev = -1;
	for(int i=1;i<=n;i++)
	{
		if(prev != -1 && s[i] == 'L')
			dist = min(dist,a[i] - a[prev]);
		else if(s[i] == 'R')
			prev = i;
	}
	if(dist == INF)
	printf("-1\n");
	else
	printf("%d\n",(dist+1)/2);
}

