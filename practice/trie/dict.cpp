//12:31
#include<bits/stdc++.h>
using namespace std;
struct trie
{
	int next[27];
	int cmp;
} *t;

int nxt;
bool flag;

void insert(char *s)
{
	int id=0;
	int i=0;
	while(i<strlen(s) && t[id].next[s[i]-'a']>0)
	id=t[id].next[s[i]-'a'],i+=1;

	while(i<strlen(s))
	{t[id].next[s[i]-'a']=++nxt,id=nxt,i+=1;}

	t[id].cmp=1;
}

void dfs(int id,char* s)
{
	if(t[id].cmp==1)
	{printf("%s\n",s);flag=false;}
	
	for(int i=0;i<26;i++)
	{
		if(t[id].next[i]>0)
		{
		int idx=strlen(s);
		s[idx]='a'+i;
		s[idx+1]='\0';
		dfs(t[id].next[i],s);
		s[idx]='\0';
		}
	}
}

void solve(char* s)
{
	int id=0;
	int i=0;
	while(i<strlen(s) && t[id].next[s[i]-'a']>0)
	id=t[id].next[s[i]-'a'],i+=1;

	if(i==strlen(s))
	{
	for(int i=0;i<26;i++)
	if(t[id].next[i]>0)
	{
		int idx=strlen(s);
		s[idx]='a'+i;
		s[idx+1]='\0';
		dfs(t[id].next[i],s);
		s[idx]='\0';
	}
	}
}



int main()
{
	char *temp=(char*)calloc(1000,sizeof(char));
	int n,k,m;
	nxt=0;
	scanf("%d",&n);
	t=(trie*)calloc(n*20+1,sizeof(trie));	
	for(int i=0;i<n;i++){
		scanf("%s",temp);
		insert(temp);
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		printf("Case #%d:\n",i+1);
		flag=true;
		scanf("%s",temp);
		solve(temp);
		if(flag)
		printf("No match.\n");
	}	
	free(t);	
}
