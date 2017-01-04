#include <stdio.h>
#include <string.h>
#include <algorithm>

const int NN = 260 ;
int N,M, A, B;
int map[NN][NN] ;
int sum[NN] ;
int sumB[NN] , sumA[NN] ;
int xx[NN*3] ;
int C[3 * NN] ;


int find( int val , int l ,int r ){
    while( l<=r ){
        int mid = (l + r) >> 1  ;
        if( xx[mid] == val )    return mid ;
        if( xx[mid] < val ) l = mid + 1 ;
        else            r = mid - 1 ;
    }
    return -1 ;
}

inline int lowbit(int a){ return a&(-a)  ; }

void add(int a , int n){
        while( a<=n ){
            C[a] ++ ; a += lowbit(a) ;
        }
}

int cal_sum(int n){
    int res = 0 ;
    while( n>=1 ){
        res += C[n]  ;
        n -= lowbit(n) ;
    }
    return res ;
}
void solve(){
    int ans = 0 ;
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j++){
            int cnt = 1 ;
            sum[0] = 0  ;
            sumA[0] = sum[0] - A ;
            sumB[0] = sum[0] - B - 1 ;
            xx[cnt++ ] = sum[0]  ;
            xx[cnt++ ] = sumA[0] ;
            xx[cnt++ ] = sumB[0] ;

            for(int k=1;k<=M;k++){
                sum[k] = sum[k-1] + map[j][k] - map[i-1][k] ;
                sumA[k] = sum[k] - A ;
                sumB[k] = sum[k] - B - 1;
                xx[cnt ++] = sum[k]  ;
                xx[cnt ++] = sumB[k] ;
                xx[cnt ++] = sumA[k] ;
            }
            std::sort( xx + 1 , xx + cnt ) ;
            int tot = 2 ;
            for(int i=2;i<cnt;i++){
                if( xx[i] == xx[i-1] )  continue ;
                xx[ tot++ ] = xx[i] ;
            }
            tot -- ;
            memset( C , 0 ,sizeof(C) );
            add( find( sum[0] , 1 , tot ) , tot ) ;
            for(int i=1;i<=M;i++){
                int e = find( sumA[i] , 1 , tot ) ;
                int s = find( sumB[i] , 1 , tot ) ;
                ans += cal_sum(e) - cal_sum(s) ;
                add( find( sum[i] ,1 , tot) , tot ) ;
            }
        }
    }
    printf("%d\n",ans);
}

int main(){
    while( scanf("%d %d",&N,&M) == 2 ){
        for(int j=1;j<=M;j++)   map[0][j] = 0 ;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                scanf("%d",&map[i][j]) ;
                map[i][j] = map[i-1][j] + map[i][j] ;
            }
        }
        scanf("%d %d",&A,&B);
        solve() ;
    }
    return 0 ;
}



