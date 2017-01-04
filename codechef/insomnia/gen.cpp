#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int x, i, j;
	for (int x = 2; x <= 100; x++) {
		int flag = 0;
		for (int i = 1; i < x; i++) {
			for (int j = i+1; j <x; j++) {
				int sum = j * (j + 1) / 2 - ((i - 1) * (i)) / 2;
				if (sum == x) {
					printf("%d - Yes, j = %d, i = %d\n", x, j, i);
					flag = 1;
					break;
				}
				
			}
			if (flag == 1)
					break;
			
		}
		if (flag == 0)
			printf("%d - No\n", x);
	}
	return 0;
}
