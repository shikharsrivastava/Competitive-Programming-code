
/*
	Simply make a trie from all given substrings. 
	The apply dfs like algorithm to store at each node two values ,win and lose
	
	win = true if the player that selects this node can win the game and vice versa for false
	lose = true when the palyer that selects this node can lose the game and vice versa for false
*/
#include<bits/stdc++.h>
using namespace std;

class trie
{
	public:
	struct node
	{
		int next[26];
		bool win;
		bool lose;
		int level;
	} *t;
	int nxt;
	trie()
	{nxt=0;t = (node*)calloc(100010,sizeof(node));	}
	
	void insert(char *s)
	{
		int id=0,i=0;
		while(i<strlen(s) && t[id].next[s[i]-'a'] >0)
		id=t[id].next[s[i]-'a'],i+=1;
	
		while(i<strlen(s))
		{
			t[id].next[s[i]-'a']=++nxt;
			id=nxt;
			i+=1;
			t[id].level=i;
		}
	}	
	int dfs(int id)
	{
		int next;
		bool leaf=true;
		t[id].win=true;
		t[id].lose=true;
		for(int i=0;i<26;i++)
		{
			next=t[id].next[i];
			if(next>0)
				{
					leaf=false;
					dfs(next);
					if(t[next].win)
					t[id].win=false;
					if(t[next].lose)
					t[id].lose=false;
				}			
		}
		if(leaf)
		t[id].lose=false;
	}
};
int main()
{
	int n,k;
	char *s=(char*)calloc(1000000,sizeof(char));
	scanf("%d %d",&n,&k);
	trie tr;
	for(int i=0;i<n;i++)
	{scanf("%s",s);	tr.insert(s);}

	tr.dfs(0);
	/*Since we are seeing the t[0] node which is the null (root) node which is not and cannot be selected by the first player we see it through the
	perspective of second player to balance , i.e. the first player moves first from any given prefixes that means that the second palyer selects the
	Root node ( balancing the sequence (....first,second,first,second.....))*/

	if(tr.t[0].win && tr.t[0].lose) //player 2 can do whatever he wants
	{
	printf("Second\n");
	}
	else if(!tr.t[0].win && !tr.t[0].lose) //player 1 can do whatever he wants
	{
	printf("First\n");
	}
	else if(tr.t[0].win) 	//1st player always loses
	{
		printf("Second\n");
	}
	else			//1st player always wins
	{
		if(k%2==0)
		printf("Second\n");
		else
		printf("First\n");
	}

}
