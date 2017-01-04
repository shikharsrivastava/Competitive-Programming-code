//1:02

#include<bits/stdc++.h>
using  namespace std;

struct trie
{
	struct node
	{
	int n[26];
	};
	int nxtp,nxts;
	long long int ans;
	node *t1,*t2;
	int *ec;
	trie()
	{
		t1=(node*)calloc(100000,sizeof(node));
		nxtp=0;
		t2=(node*)calloc(100000,sizeof(node));
		nxts=0;
		ec=(int*)calloc(26,sizeof(int));
		ans=0;
	}
	void clear()
	{
		free(t1);
		free(t2);
		t1=(node*)calloc(100000,sizeof(node));
		nxtp=0;
		t2=(node*)calloc(100000,sizeof(node));
		nxts=0;
		ec=(int*)calloc(26,sizeof(int));
		ans=0;
	}
	void insert(char *s)
	{
		int id=0,i=0;
		while(i<strlen(s) && t1[id].n[s[i]-'a']>0)
		id=t1[id].n[s[i]-'a'],i+=1;

		while(i<strlen(s))
		{
			t1[id].n[s[i]-'a']=++nxtp;
			id=t1[id].n[s[i]-'a'];
			i+=1;
		}
	}
	void insertrev(char *s)
	{
	int id=0,i=strlen(s)-1;
	while(i>=0 && t2[id].n[s[i]-'a']>0)
	id=t2[id].n[s[i]-'a'],i-=1;

	while(i>=0)
	{
		t2[id].n[s[i]-'a']=++nxts;
		if(i<strlen(s)-1)
		ec[s[i]-'a']++;
		id=t2[id].n[s[i]-'a'];
		i-=1;	
	}
	}
	

	void dfs(int id)
	{
		for(int i=0;i<26;i++)
		{
			if(t1[id].n[i]>0)
			{
				ans+=nxts-ec[i];
				dfs(t1[id].n[i]);
			}
		}
	}
	void findans()
	{
		for(int i=0;i<26;i++)
		{
			if(t1[0].n[i]>0)
			{
				ans+=nxts;
				dfs(t1[0].n[i]);
			}
		}
	}
};

int main()
{
	int n,m;
	char *s=(char*)calloc(10000,sizeof(char));
	trie tr;
	scanf("%d %d",&n,&m);
	while(n != 0 || m !=0)
	{
	for(int i=0;i<n;i++)
	{
	scanf("%s",s);
	tr.insert(s);
	}
	for(int i=0;i<m;i++)
	{
	scanf("%s",s);
	tr.insertrev(s);
	}
	
	
	tr.findans();
	printf("%lld\n",tr.ans);
	tr.clear();
	scanf("%d %d",&n,&m);	
	}
	return 0;
}
