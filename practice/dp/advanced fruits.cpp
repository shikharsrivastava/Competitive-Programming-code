
#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
string locs[105][105];
string lcs(char *s1,char* s2)
{
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	for(int i=0;i<=l1;i++)
		for(int j=0;j<=l2;j++)
			locs[i][j] = "";

	memset(dp,0,sizeof(dp));

	for(int i=0;i<l1;i++)
		for(int j=0;j<l2;j++)
			if(s1[i] == s2[j])
				dp[i+1][j+1] = 1 + dp[i][j] , locs[i+1][j+1] = locs[i][j] + s1[i];
			else
			{
				dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
				if(dp[i+1][j+1] == dp[i][j+1])
					locs[i+1][j+1] = locs[i][j+1];
				else
					locs[i+1][j+1] = locs[i+1][j];
			}	
	return locs[l1][l2];
}
int main()
{
	char s1[102],s2[102];
	while(scanf("%s %s",s1,s2) != EOF)
	{
		string ans = lcs(s1,s2);
		int ind = 0,i=0,j=0;
		while(ind<ans.length())
		{
			while(i<strlen(s1) && s1[i] != ans[ind])
			{printf("%c",s1[i]); i++;}
			while(j<strlen(s2) && s2[j] != ans[ind])
			{printf("%c",s2[j]);j++;}
			printf("%c",ans[ind]);
			i++,j++,ind++;
		}
		while(i<strlen(s1) && s1[i] != ans[ind])
		{printf("%c",s1[i]); i++;}
		while(j<strlen(s2) && s2[j] != ans[ind])
		{printf("%c",s2[j]);j++;}
		printf("\n");
	}
}
