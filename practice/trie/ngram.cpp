#include<bits/stdc++.h>
using namespace std;

vextor<vector<string>> p;
struct trie
{
	struct node
	{
		int n[26];
		int cnt;
	} *t;
	int nxt;
	int j;
	char *ans;
	trie()
	{
		t=(node*)calloc(100000,sizeof(node));
		ans=(char*)calloc(10000,sizeof(char));
		nxt=0;
		j=0;
	}
	void clear()
	{
		free(t);
		free(ans)
		t=(node*)calloc(100000,sizeof(node));
		ans=(char*)calloc(10000,sizeof(char));
		nxt=0;
		j=0;
	}
	void insert(char *s)
	{
		int id=0,i=0;
		while(i<strlen(s) && t[id].n[s[i]-'a'] >0)
		id=t[id].n[s[i]-'a'],t[id].cnt+=1,i+=1;
		while(i<strlen(s))
		{
			t[id].n[s[i]-'a']=++nxt;
			id=t[id].n[s[i]-'a'];
			t[id].cnt+=1;
			i+=1;
		}

	}
	void dfs(int id)
	{	
		int m=0,nid=0,char c;
		for(int i=0;i<26;i++)
		{
			int next=t[id].n[s[i]-'a'];
			if(t[next].cnt >m)
			{
			c=s[i];
			m=t[next].cnt;
			nid=next;	
			}
		}
		if(m>0)
		{
		char[j++]=c;
		dfs(nid);	
		}
	}	

}



int main()
{
	int t,n;
	char c;
	string temp;
	trie tr;
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<n;i++)
		{
		c=getchar_unlocked();
		if()
		}	
	
	}
}
