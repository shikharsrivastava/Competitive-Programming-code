#include<bits/stdc++.h>
using namespace std;

void printans(int k)
{
	if(k==1)
	{printf("%d\n",1);return;}
	queue<int> q;
	int vis[k+1];
	int pre[k+1];
	memset(vis,0,sizeof(vis));
	memset(pre,0,sizeof(pre));
	q.push(1);
	vis[1] = 2;
	while(!q.empty())
	{
		int md = q.front();
		if(md == 0)
		break;
		q.pop();

		int m2 = (md*10)%k;

		if(!vis[m2])
		{

			vis[m2] = 1;
			q.push(m2);
			pre[m2] = md;
		}

	
		int m1 = ((md * 10) +1) %k;
		if(!vis[m1])
		{
			vis[m1] = 2;
			q.push(m1);
			pre[m1] = md;

		}

		
	}
	vector<int> s;
	int md = 0;
	while(md != 1)
	{
		s.push_back(vis[md] == 2 ? 1:0);
		md = pre[md];
	}
	s.push_back(1);
	for(int i=s.size()-1;i>=0;i--)
	printf("%d",s[i]);
	printf("\n");	
}

int main()
{
	int t,k,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&k);
		printans(k);
	}
}
