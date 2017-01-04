    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    #define pii pair<int,int>
    #define mp make_pair
    vector<vector<int> > g(10005);
    bool inf[10004];
    bool vacc[10004];
    int depth[10004];
    int main()
    {
    	int n,m,k,s,u,v;
    	scanf("%d %d %d %d",&n,&m,&k,&s);
    	
    	int w[n+1];
    	for(int i=1;i<=n;i++)
    	scanf("%d",&w[i]);
    	
    	for(int i=1;i<=m;i++)
    	{
    		scanf("%d %d",&u,&v);	
    		g[u].pb(v);
    		g[v].pb(u);
    	}
    	inf[s] = true;
    	priority_queue<pii> q;
    	for(int i=1;i<=n;i++)
    		if(!inf[i])
    			q.push(mp(w[i],i));	
    	
    	queue<int> bfsq;
    	bfsq.push(s);
    	depth[s] = 1;
    	int when = 1;
    	int saved = 0;
    	while(!bfsq.empty())
    	{
    		int node = bfsq.front();
    		bfsq.pop();
    		int mx = 0;
    		if(depth[node] == when)
    		{
    			when++;
    			while(!q.empty())
    			{
    				int ind = q.top().second;
    				q.pop();
    				if(inf[ind])
    				continue;
    				else
    				{
    					printf("%d ",ind);
    					saved++;
    					vacc[ind] = true;
    					break;
    				}
    			}
    			if(q.empty() || saved == k)
    			break;
    		}
    		if(vacc[node])
    			continue;
    		for(int i=0;i<g[node].size();i++)
    			if(!vacc[g[node][i]] && depth[g[node][i]] == 0)
    				inf[g[node][i]] = true , depth[g[node][i]] = depth[node]+1 , bfsq.push(g[node][i]);
    			
    	}
    	
    	for(int i=saved;i<k;i++)
    	printf("%d ",s);
    	printf("\n");
     
    	
    	
    } 
