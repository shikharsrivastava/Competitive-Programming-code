//11:56 - 12 :09
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,n,*w,*wl;	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		w=(int*)calloc(n+1,sizeof(int));
		wl=(int*)calloc(n+1,sizeof(int));
	
		for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
		for(int i=1;i<=n;i++)
		scanf("%d",&wl[i]);
	
		sort(w+1,w+n+1);
		sort(wl+1,wl+n+1);
	
		int ans=0;
		for(int i=1,j=1;i<=n && j<=n;)
		{
			if(w[i] <= wl[j])
			{ans++;j++;i++;}
			else
			j++;
		}
		free(w);
		free(wl);
		printf("%d\n",ans);
	}
}
