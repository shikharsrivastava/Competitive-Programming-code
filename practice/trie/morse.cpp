//23:50
#include<bits/stdc++.h>
using namespace std;
int *dp,nxt;
string ms;
struct trie
{
	int next[2];
	int cmp;
} *t;

string morse[26]={"01","1000","1010","100","0","0010","110","0000","00","0111","101","0100","11","10","111","0110","1101","010","000","1","001","0001","011","1001","1011","1100"};

void insert(string s)
{
	int id=0;
	int i=0;
	int j=0;
	while(i<s.length())
	{
		j=0;
		for(;(j<morse[s[i]-'A'].length()) && t[id].next[morse[s[i]-'A'][j]-'0'] >0 ;j++)
		id=t[id].next[morse[s[i]-'A'][j]-'0'];
		
	if(j<morse[s[i]-'A'].length())
	break; 	
	i++;
	}
	
	while(i<s.length())
	{
		for(;j<morse[s[i]-'A'].length();j++)
		{t[id].next[morse[s[i]-'A'][j]-'0']=++nxt;id=nxt;}
		j=0;
		i++;
	}
	t[id].cmp++;
	
}

int findans(int i)
{
	int ans=0;
	int id=0;
	//printf("i = %d \n",i);
	while(i<ms.length() && t[id].next[ms[i]-'0'] >0)
	{
		id=t[id].next[ms[i]-'0'];
		if(t[id].cmp>0)
		{ans+=t[id].cmp*dp[i+1];/*printf("Matched at %d words completed = %d dp[%d] = %d\n",i,t[id].cmp,i+1,dp[i+1]);*/}
		i++;
	}
	//printf("ans = %d\n",ans);
	return ans;
}

int main()
{
	int d,tmp;
	scanf("%d",&d);
	string temp;
	while(d--)
	{
	nxt=0;
	cin>>ms;
	for(int i=0;i<ms.length();i++)
	{if(ms[i]=='.')ms[i]='0';else ms[i]='1';}
	dp=(int*)calloc(ms.length()+2,sizeof(int));
	for(int i=1;i<ms.length();i++)
	dp[i]=-1;
	dp[ms.length()]=1;

	int n;
	scanf("%d",&n);
	t=(trie*)calloc(n*20*4+2,sizeof(trie));	
	for(int i=0;i<n;i++)
	{cin>>temp;insert(temp);}

	for(int i=ms.length()-1;i>=0;i--)
		{tmp=findans(i);if(tmp>0)dp[i]=tmp;}
	printf("%d\n",dp[0]);
	free(dp);
	free(t);
	
	}
}
