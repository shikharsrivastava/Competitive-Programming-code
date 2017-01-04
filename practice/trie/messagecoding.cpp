//2:17
#include<bits/stdc++.h>
using namespace std;
map<char,int> mp;
string str[10100];
int *dp,*a;
int n;
#define MAXX 1000000000
struct trie
{
	struct node
	{
		int nx[10];
		bool end; 
	} *t;
	int nxt;
	trie()
	{
	t=(node*)calloc(1000000,sizeof(node));
	nxt=0;
	}

	void clear()
	{
	free(t);
	t=(node*)calloc(1000000,sizeof(node));
	nxt=0;
	}
	
	void insert(string s)
	{
	int id=0,i=0;
	while(i<s.length() && t[id].nx[mp.find(s[i])->second]>0)
	id=t[id].nx[mp.find(s[i])->second],i+=1;

	while(i<s.length())
	{
		t[id].nx[mp.find(s[i])->second]=++nxt;
		id=t[id].nx[mp.find(s[i])->second];
		i+=1;
	}
	t[id].end=true;

	}


	int findans(int id,int ind)
	{
		int ans=MAXX;		
		if(t[id].end)
			ans=min(ans,dp[ind+1]+1);
		if(ind==n)
		return ans;
		
		
		 
		if(t[id].nx[a[ind+1]] > 0)
				ans=min(ans,findans(t[id].nx[a[ind+1]],ind+1));
	
		return ans;
	}
	
};

int main()
{
	int tc,k,d,m;
	char c;
	trie tr;
	scanf("%d",&tc);
	
	for(int tno=1;tno<=tc;tno++)
	{
		scanf("%d",&k);
		for(int i=0;i<k;i++)
		cin>>str[i];
		for(int i=0;i<10;i++)
		{
			scanf("%d %d",&d,&m);
			for(int j=0;j<m;j++)
			{
				cin>>c;
				mp.insert(pair<char,int>(c,d));			
			}
		}
		
		for(int i=0;i<k;i++)
			tr.insert(str[i]);

		
		scanf("%d",&n);	
		dp=(int*)calloc(n+3,sizeof(int));
		a=(int*)calloc(n+1,sizeof(int));
		for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

			
		for(int i=n-1;i>=0;i--)
		{
		if(tr.t[0].nx[a[i]]>0)
		dp[i]=tr.findans(tr.t[0].nx[a[i]],i);
		else
		dp[i]=MAXX;
		}	
		if(dp[0]==MAXX)
		printf("Case %d: %d\n",tno,-1);
		else	
		printf("Case %d: %d\n",tno,dp[0]);
		free(a);
		free(dp);
		tr.clear();
		mp.clear();
		
	}
}
