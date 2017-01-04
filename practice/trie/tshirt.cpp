/*
	Simple question we make a trie from all the strings and on each node of trie amrk how many times it comes in set 1 and set 2

	After inserting all the strings we use modified bfs to reach the longest common prefix from both the sets

	On reaching that node we take its length as the longest prefix match found and from there start going upwards on the trie
	
	Now since we have found the longest match , to find the next longest match we have to delete this prefix from the trie , 
	
	But since there can be dublicates , we keep a count of how many times this prefix has come in set 1 and 2 , with st[3] array

	Now since we have used up the entire prefix till longest match we decrease the count of all prefixies of this longest prefix in both sets
	
	by 1 since we all words in the longest prefix are gone once.
*/
#include<bits/stdc++.h>
using namespace std;
class trie
{	
	public:
	int next[26];		// stores the links to next nodes
	int st[3];		// stores the nuber of times this prefix occurs in both the sets 
	int parent;		// stores the index of the parent of this node
	int level;		// stores the length from root to this node
	int idx; 		//strores the index of current node in array

} *t;
int nxt;

/*function to insert the string in trie , where is is the set from which we are inserting it , to incerease the count of prefix in each set*/
void insert(char *s,int f)
{
	int id=0,i=0;
	
	while(i<strlen(s) && t[id].next[s[i]-'A']>0)
	{
	id=t[id].next[s[i]-'A'];
	t[id].st[f]+=1;
	i+=1;
	}

	while(i<strlen(s))
	{
		t[id].next[s[i]-'A']=++nxt;
		t[nxt].parent=id;
		id=nxt;
		t[id].st[f]+=1;
		t[id].idx=id;
		t[id].level=i+1;
		i+=1;
	}	
	
}
/*Simple modified bfs function o find the longest common prefix from both sets and the decrease count of all of its prefixes by 1
	
	-> Returns the length of longest common prefix from both sets
*/
int longestmatch()
{
	int ans=0,id=0;
	queue<trie> q;
	trie tmp;
	q.push(t[id]);
	while(!q.empty())
	{
		tmp=q.front();
		q.pop();
		for(int i=0;i<26;i++)
		{
			if(tmp.next[i]>0 && t[tmp.next[i]].st[1]>0 && t[tmp.next[i]].st[2]>0)
			q.push(t[tmp.next[i]]);
		}
	}
	ans=tmp.level;
	/*Decreasing the count of all prefix of longest common prefixes by one since the longest common prefix is used from both sets
	  so the number of times its prefixes occur in both setss decrease by 1	
	*/
	while(tmp.level !=0)
	{
		t[tmp.idx].st[1]--;
		t[tmp.idx].st[2]--;
		tmp=t[tmp.parent];
	}	
	return ans;
}
int main()
{
	int n,ans=0,tmp;
	scanf("%d",&n);
	char *s=(char*)calloc(105,sizeof(char));
	while(n!= -1)
	{
		ans=0;
		nxt=0;
		t=(trie*)calloc(n*200+100,sizeof(trie));
		for(int i=0;i<n;i++)
		{
			scanf("%s",s);
			insert(s,1);		
		}

		for(int i=0;i<n;i++)
		{
			scanf("%s",s);
			insert(s,2);
		}		
		for(int i=0;i<n;i++)
		{
			tmp=longestmatch();
			if(tmp==0)
			break;
			ans+=tmp;
		}
		printf("%d\n",ans);
		free(t);
		scanf("%d",&n);
	}
	free(s);

}
