//1:48
#include<bits/stdc++.h>
	
using namespace std;

struct trie
{
	struct node
	{
		int n[2];
		int count;	
	} *t;
	
	int nxt;
	int ans;
	trie()
	{
	t=(node*)calloc(100000,sizeof(node));
	nxt=ans=0;
	}
	
	void clear()
	{
	free(t);
	t=(node*)calloc(100000,sizeof(node));
	nxt=ans=0;
	}	
	void insert(char *s)
	{
		int id=0,i=0;
		while(i<strlen(s) && t[id].n[s[i]-'0']>0)
		id=t[id].n[s[i]-'0'],i+=1,t[id].count+=1;

		while(i<strlen(s))
		{
			t[id].n[s[i]-'0']=++nxt;
			id=t[id].n[s[i]-'0'];
			t[id].count++;
			i++;
		}
	}
	
	void dfs(int id,int l)
	{
		if(((t[id].count)*l) >ans)
		ans=t[id].count*l;

		for(int i=0;i<2;i++)
		{
			if(t[id].n[i]>0)
			dfs(t[id].n[i],l+1);
		}
	}
	
};

int main()
{
	int t,n;
	trie tr;
	scanf("%d",&t);
	char *s=(char*)calloc(100000,sizeof(char));
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		tr.insert(s);
	}
		tr.dfs(0,0);
		printf("%d\n",tr.ans);
		tr.clear();
		
	}
}
