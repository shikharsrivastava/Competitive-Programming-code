//19:48
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,n;
	int *a,*b,ans;
	char *s;
	vector<int> pos;
	scanf("%d",&t);	
	while(t--)
	{
		ans = 0;
		pos.clear();
		scanf("%d",&n);
		a=(int*)calloc(n+2,sizeof(int));
		b=(int*)calloc(n+2,sizeof(int));
		s = (char*)calloc(n+2,sizeof(char));
		scanf("%s",&s[1]);
		for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		
		for(int i=1;i<=n;i++)
		if(s[i] == '1')
		pos.push_back(i);
		
		if(s[1] == '0')
		ans += a[pos[0]] - a[1];
		if(s[n] == '0')
		ans += a[n] - a[pos[pos.size()-1]];

		int tempans;		
		for(int i=0;i<pos.size()-1;i++)
		{
			tempans = 1000000001;
			for(int j=pos[i];j<pos[i+1];j++)
			tempans = min(tempans,(a[j]-a[pos[i]] + a[pos[i+1]] - a[j+1]));
			ans += tempans;
		}
		printf("%d\n",ans);
		free(a);
		free(b);
		free(s);
	}
}
