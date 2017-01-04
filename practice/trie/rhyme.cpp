/*
	Simple question on trie
	
	First sort all the words and give them sorted id

	Insert words in trie in reverse order

	Each node saves the id of lexicographically smallest and second smallest string that contains string till that node as a suffix
	
	The root saves id of lexicographically smallest string in m1 (m1=0) , which is printed if no match is found;
	
	It save 2nd smallest string in m2 (m2=1) , which is printed if lexicographically smallest string is given as input
*/

#include<bits/stdc++.h>
using namespace std;
string str[250005];
struct trie
{
	
	int nxt;
	struct node
	{
		int next[26];
		int parent;
		int m1;
		int m2;
	} *t;
	trie()
	{
	t=(node*)calloc(7000000,sizeof(node));
	nxt=0;
	}
	~trie()
	{
	free(t);
	}
	void insert(string s,int h)
	{
		int id=0,i=s.length()-1;
		while(i>=0 && t[id].next[s[i]-'a']>0)
		{
			id=t[id].next[s[i]-'a'];
			t[id].m2=t[id].m1;
			t[id].m1=h;
			i-=1;
		}
		
		while(i>=0)
		{
			t[id].next[s[i]-'a']=++nxt;
			t[nxt].parent=id;
			id=nxt;
			t[id].m1=h;
			t[id].m2=h;
			i-=1;
		}
	}
	int find(string s)
	{
		int id=0;
		int i=s.length()-1;

		while(i>=0 &&t[id].next[s[i]-'a']>0)
		id=t[id].next[s[i]-'a'],i-=1;
		
		while(id>=0 && str[t[id].m1]==s)
		{
			if(str[t[id].m2] != s)
			return t[id].m2;
			id=t[id].parent;
		}
		return t[id].m1;			
	}

};
bool takeinput(string &s)
{
	s="";
	char c=getchar_unlocked();
	while(c>='a' && c<='z')
	{
		s+=c;
		c=getchar_unlocked();
	}
	if(s=="")
	return false;
	return true;
}
	

int main()
{
	int n,i=0;
	scanf("%d",&n);
	string pat;
	while(takeinput(str[i]))
	i++;

	sort(str,str+i);
	trie tr;
	tr.t[0].m1=0;
	tr.t[0].m2=1;
	for(int j=i-1;j>=0;j--)
	tr.insert(str[j],j);
	
	while(takeinput(pat))
	cout<<str[tr.find(pat)]<<endl;

}
