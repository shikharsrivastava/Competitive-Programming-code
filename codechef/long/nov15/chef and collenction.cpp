    #include<cstdio>
    #include<cstdlib>
    #include<vector>
    #include<algorithm>
     
    using namespace std;
     
    class offer
    {
    public:
    int day;
    int a;
    int b;
    };
     
    class edges
    {
    public:
    int day;
    int max;
    int dest;
    edges(int d,int m,int de)
    {
    day=d;
    max=m;
    dest=de;
    }
    };
     
    class node
    {
    public:
    int val;
    int max;
    vector<int> neighbours;
    vector<edges> edge;
    };
     
     
     
    node* graph;
    bool* visited;
     
    void recurse(int index,int mx,int prevday)
    {
     
    int va,vb;
     
    if(visited[index]==false)
    {
    visited[index]=true;
    graph[index].max=mx;
    }
     
    for(int i=0;i<(int)graph[index].edge.size();i++)
    {
    	va=graph[index].val;
    	vb=graph[index].edge[i].dest;
     
    	
    	if(graph[index].edge[i].day>prevday)
    	break;
    	if(graph[index].edge[i].max<mx)
    	{
    	graph[index].edge[i].max=mx;
    	recurse(vb,mx,graph[index].edge[i].day);
    	}
    }
     
     
    }
     
    bool so(const offer &x , const offer &y)
    {
    	if(x.day != y.day)
    	return x.day < y.day;
    	else 
    	{
    	if(x.a != y.a)
    	return x.a < y.a;
    	else
    	return x.b<y.b;
    	}
     
    }
     
    using namespace std;
     
    int main()
    {
     
    int t,n,maxx,m,va,vb,*a,*hash;
    long long int ans;
    offer* o;
    scanf("%d",&t);
    while(t--)
    {
     
    maxx=ans=0;
    scanf("%d %d",&n,&m);
     
    o=(offer*)calloc(m+1,sizeof(offer));
    graph=(node*)calloc(50001,sizeof(node));
    visited=(bool*)calloc(50001,sizeof(bool));
    a=(int*)calloc(n+1,sizeof(int));
     
    for(int i=1;i<=50000;i++)
    graph[i].max=i;
     
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
     
    for(int i=1;i<=m;i++)
    {
    scanf("%d %d %d",&o[i].day,&o[i].a,&o[i].b);
    maxx=maximum(maxx,o[i].a);
    maxx=maximum(maxx,o[i].b);
    }
     
     

    sort(o+1,o+m+1,so);
     
     
    for(int i=1;i<=m;i++)
    {
    va=o[i].a;
    vb=o[i].b;
     
    graph[va].val=va;
    graph[vb].val=vb;
     
     
    graph[va].edge.push_back(edges(o[i].day,0,vb));
    graph[vb].edge.push_back(edges(o[i].day,0,va));
     
    }
     
 
    for(int i=maxx;i>=0;i--)
    recurse(i,i,1000000);
     
     
    for(int i=1;i<=n;i++)
    ans+=graph[a[i]].max;
     
    printf("%lld\n",ans);
     
  
    free(a);
    free(o);
    free(graph);
    free(visited);
    }
     
    } 
