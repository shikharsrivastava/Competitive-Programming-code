#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
inline lli findmin(lli a=LLONG_MAX,lli b=LLONG_MAX,lli c=LLONG_MAX,lli d=LLONG_MAX,lli e = LLONG_MAX)
{
	return min(a,min(b,min(c,min(d,e))));
}

inline int md(int a,int b)
{
	int ret = a%b;
	if(ret <0)
	ret += b;
	return ret;
}

int main(void) {
    int t,n,st,en,nxt,prev,*edge;
	bool flag;
	lli *sclock,*santi,*tclock,*tanti,*add,*addrev,current,ans;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
		sclock = (lli*)calloc(n+2,sizeof(lli));
		santi = (lli*)calloc(n+2,sizeof(lli));
		tclock = (lli*)calloc(n+2,sizeof(lli));
		tanti = (lli*)calloc(n+2,sizeof(lli));
		add = (lli*)calloc(n+2,sizeof(lli));
		addrev = (lli*)calloc(n+2,sizeof(lli));
		edge = (int*)calloc(n+2,sizeof(int));

        for (int i = 0; i < n; i++)
            scanf("%d", &edge[i]);

        scanf("%d %d", &st, &en);
        st--, en--;
        int u = md(st+1,n);
        current = edge[st];
        while (true) 
		{
            sclock[u] = current;
            if (u == st)
                break;
            current += edge[u];
            u = md(u+1,n);
        }

        u = md(st-1,n);
        current = edge[u];
        while (true) 
		{
            santi[u] = current;
            if (u == st)
                break;
            u = md(u-1,n);
            current += edge[u];
        }

        u = md(en+1,n);
        current = edge[en];
        while (true) 
		{
            tclock[u] = current;
            if (u == en)
                break;
            current += edge[u];
            u = md(u+1,n);
        }

        u = md(en-1,n);
        current = edge[u];
        while (true) 
		{
            tanti[u] = current;
            if (u == en)
                break;
            u = md(u-1,n);
            current += edge[u];
        }


        lli ans = LLONG_MAX;
		flag = false;
		ans = findmin(ans,sclock[en],santi[en],sclock[en]+tanti[en],santi[en]+tclock[en]);


        add[en] = 0;
        u = md(en-1,n);

        while (u != st) 
		{
            nxt = md(u+1,n);
            add[u] = min(add[nxt], tanti[u] + tanti[u]);
            u = md(u-1,n);
        }

        addrev[en] = 0;
        u = md(en+1,n);
        while (u != st) 
		{
            prev = md(u-1,n);
            addrev[u] = min(addrev[prev], tclock[u] + tclock[u]);
            u = md(u+1,n);
        }

        u = md(st+1,n);
        while (true) 
		{
            if (u == st)
                break;
            if (u == en) 
			{
                flag = true;
                u = md(u+1,n);
                continue;
            }
            if (flag == false) 
				ans = findmin(ans,sclock[u]+tclock[u],sclock[u]+tclock[u]+add[u],santi[u]+tanti[u]);
            
            else 
				ans = findmin(ans,santi[u]+tanti[u],santi[u]+tanti[u]+addrev[u],sclock[u]+tclock[u]); 
            
            u = md(u+1,n);
        }
		free(sclock);
		free(santi);
		free(tclock);
		free(tanti);
		free(add);
		free(addrev);
		free(edge);
        printf("%lld\n", ans);
    }
    return 0;
}

