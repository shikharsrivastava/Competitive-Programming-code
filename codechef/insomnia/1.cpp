#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
typedef long long lli;


int main(void) {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int cnt = __builtin_popcount(n);
		if (cnt == 1)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}
