//2:26
#include<bits/stdc++.h>
using namespace std;

struct trie
{
	struct node
	{
	int n[26];
	int link;
	int p;
	int count;
	int l;
	} *t;
	int nxt;
	long long int ans;	
	trie()
	{
	t=(node*)calloc(1000000,sizeof(node));
	nxt=ans=0;
	}
	
	void clear()
	{
		free(t);
		t=(node*)calloc(1000000,sizeof(node));
		nxt=ans=0;
	}
	void insert(char *s)
	{
		int id=0,i=0;
		while(i<strlen(s) && t[id].n[s[i]-'a']>0)
		id=t[id].n[s[i]-'a'],t[id].count+=1,i+=1;
		
		int tmp,lnk=id;

		while(i<strlen(s))
		{
			t[id].n[s[i]-'a']=++nxt;	
			tmp=id;
			id=t[id].n[s[i]-'a'];
			t[id].p=tmp;
			t[id].count++;
			t[id].l=i+1;
			i++;
		}
		id=lnk;
		//printf("link is %d\n",id);
		while(id>0)
		{
			if(t[id].link >0)
			{
				if(t[t[id].link].l <t[lnk].l)
				break;
			}
			t[id].link=lnk;
			id=t[id].p;
		}

	}

	void go(int id)
	{	
		int next;
		for(int i=0;i<26;i++)
		{
			if(t[id].n[i] >0)
			{
				next=t[id].n[i];
				ans+=t[next].count;
				if(t[next].link >0)
				go(t[next].link);
			}
		}
	}
};

int main()
{
	int n;
	trie t;
 	char *s=(char*)calloc(100000,sizeof(char));

		while(scanf("%d",&n) != EOF)
	{
		for(int i=0;i<n;i++)
		{
		scanf("%s",s);
		t.insert(s);
		}
		
		t.go(0);
		printf("%0.2lf\n",(double)t.ans/n);
		t.clear();
	}
	return 0;
}
