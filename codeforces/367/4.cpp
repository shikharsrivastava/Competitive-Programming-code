//14:57
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int nxt[2];
	int c[2];
};
struct trie
{
	node * t;
	int nxt;
	trie()
	{
		nxt = 0;
		t = (node*)calloc(10000000,sizeof(node));
	}
	
	void insert(int num)
	{
		int k = 31,id = 0;
		while(k >= 0 && t[id].nxt[(num>>k)&1] > 0)
		t[id].c[(num>>k)&1]++, id = t[id].nxt[(num>>k)&1] , k--;
		
		while(k>=0)
		{
			//printf("Inserting %d\n",(num>>k)&1);
			t[id].nxt[(num>>k)&1] = ++nxt;
			t[id].c[(num>>k)&1]++;
			id = t[id].nxt[(num>>k)&1];
			k--;
		}
		//printf("nxt  = %d\n",nxt);
	}
	void del(int num)
	{
		int k = 31,id = 0;
		while(k >= 0 && t[id].nxt[(num>>k)&1] > 0)
		t[id].c[(num>>k)&1]--, id = t[id].nxt[(num>>k)&1] , k--;
	}
	int find(int num)
	{
		int k = 31,id = 0;
		int ans = 0;
		while(k>=0)
		{
			int bit = ((num>>k)&1)^1;
			//printf("Bit = %d\n",bit);
			if(t[id].nxt[bit] > 0 && t[id].c[bit] >0)
			{
				//printf("Found %d\n",bit);
				ans |= (1<<k);
				id = t[id].nxt[bit];
			}
			else if(t[id].nxt[bit^1]>0 && t[id].c[bit^1] >0)
			{
				//printf("FFFound %d\n",bit);
				bit ^= 1;
				ans |= (0<<k);
				id = t[id].nxt[bit];			
			}
			else
			return num;
			k--;
		}
		return ans;
	}
};

int main()
{
	trie tr;
	tr.insert(0);
	int q,n;
	char c;
	scanf("%d",&q);
	while(q--)
	{
		scanf(" %c %d",&c,&n);
		if(c == '+')
		tr.insert(n);
		else if(c == '-')
		tr.del(n);
		else if(c == '?')
		printf("%d\n",tr.find(n));
	}	
}


