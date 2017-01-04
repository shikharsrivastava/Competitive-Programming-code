#include<bits/stdc++.h>
using namespace std;

int main()
{
	int hash[200];	
	memset(hash,0,sizeof(hash));
	char str[27],w[13];
	int n;
	
	scanf("%s",str);
	for(int i=0;i<strlen(str);i++)
		hash[str[i]-'a'] = 1;
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		bool f= true;
		scanf("%s",w);
		for(int i=0;i<strlen(w);i++)
			if(!hash[w[i]-'a'])
				{f =false;break;}
		if(f)
			printf("Yes\n");
		else
			printf("No\n");
	}
}
