#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <set>
#include <cstdlib>
#include <sstream>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>
#include<bits/stdc++.h>

#define REP(i,n) for(int i=0;i<n;i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define pb push_back
#define rev(ar) reverse(ar.begin(),ar.end())
#define sor(ar) sort(ar.begin(),ar.end())
#define VI vector<int> 
#define VS vector<string>
#define GI ({int y;scanf("%d",&y);y;})
typedef long long int LL;
using namespace std;
typedef pair<int,double> PII;

int K,N,M;
double C[128][64][32][4];
int enc[128][64][32][4];

inline int encode(int c,int elem,int k,int last){
	int t = 0;
	t = last;
	t = t*101 + k;
	t = t*101 + elem;
	t = t*101 + c;
	return t;
}


int main(){
	while((K=GI) + (N=GI) + (M=GI)){
		vector<PII> V;
		memset(C,0,sizeof(C));
		REP(i,N){
			int a = GI,b = GI;
			V.pb(PII(a,b));	
		}
		double ret = 0,av;
		int newl;
		
		FOR(c,0,M) 
		REPV(i,V){
			int cost = V[i].first;double val = V[i].second;
			if(c+cost<=M) REP(it,N) for(int k=K;k>=0;k--) FOR(l,1,2) if((!c && !k) || C[c][it][k][l]>.3){
				if(i!=it || !c) newl = 1,av = val;
				else if(l==1) newl = 2,av = val/2;
				else if(l==2) newl = 2,av = 0;
				if(C[c][it][k][l] + av > C[c+cost][i][k+1][newl] ){
					C[c+cost][i][k+1][newl] = C[c][it][k][l] + av;
					enc[c+cost][i][k+1][newl] = encode(c,it,k,l);
				}														 
			}
		}
		int cc = 0,itit,ll,kk;
		FOR(c,0,M) REP(it,N) FOR(l,1,2) if( C[c][it][K][l] > ret){
			ret = C[c][it][K][l];	
			cc = c;itit = it;kk = K;ll = l;
		}
		printf("%.1lf\n",ret);
		VI tt;
		while( cc && ret>.3){
			tt.pb(itit+1);
			int t = enc[cc][itit][kk][ll];
			cc = t%101;t/=101;
			itit = t%101;t/=101;
			kk = t%101;t/=101;
			ll = t;
		}
		REPV(i,tt) printf("%d ",tt[i]);
		printf("\n");		
	}	
		
}
