#include <bits/stdc++.h>
using namespace std;

struct node {
	int freq[11];
	int lazy;
} tree[500100];

int nfreq[100];

int n, q;

void build(int i, int l, int r) {
	if (l == r) {
		tree[i].freq[0] = 1;
	}
	else {
		int mid = (l + r) / 2;
		build(2*i, l, mid);
		build(2*i+1, mid + 1, r);
		tree[i].freq[0] = tree[2*i].freq[0] + tree[2*i+1].freq[0];
	}
}

void propagate(int id, int l, int r) {
	if (tree[id].lazy != 0) {
		for (int i = 0; i < 10; i++) {
			nfreq[(i + tree[id].lazy) % 10] = tree[id].freq[i];
		}
		for (int i = 0; i < 10; i++) {
			tree[id].freq[i] = nfreq[i];
		}
		if (l != r) {
			tree[2*id].lazy = (tree[2*id].lazy + tree[id].lazy) % 10;
			tree[2*id+1].lazy = (tree[2*id+1].lazy + tree[id].lazy) % 10;
		}
		tree[id].lazy = 0;
	}
}

void update(int l, int r, int id = 1, int cl = 1, int cr = n) {
	propagate(id, cl, cr);
	if (cl > r || cr < l)
		return;
	else if (cl >= l && cr <= r) {
		for (int i = 0; i < 10; i++) 
			nfreq[(i + 1) % 10] = tree[id].freq[i];
		for (int i = 0; i < 10; i++) 
			tree[id].freq[i] = nfreq[i];
		if (cl != cr) {
			tree[2*id].lazy = (tree[2*id].lazy + 1) % 10;
			tree[2*id + 1].lazy = (tree[2*id + 1].lazy + 1) % 10;
		}
	}
	else {
		int mid = (cl + cr) / 2;
		update(l, r, 2*id, cl, mid);
		update(l, r, 2*id + 1, mid + 1, cr);
		for (int i = 0; i < 10; i++) 
			tree[id].freq[i] = (tree[2*id].freq[i] + tree[2*id + 1].freq[i]);
	}
}

int query(int l, int r, int id = 1, int cl = 1, int cr = n) {
	propagate(id, cl, cr);
	if (cl > r || cr < l)
		return 0;
	else if (cl >= l && cr <= r) {
		int sum = 0;
		for (int i = 0; i < 10; i++) 
			sum += tree[id].freq[i] * i;
		return sum;
	}
	else {
		int mid = (cl + cr) / 2;
		int left = query(l, r, 2*id, cl, mid);
		int right = query(l, r, 2*id + 1, mid + 1, cr);
		return left + right;
	}
}

int main(void) { 
	scanf("%d %d", &n, &q);
	build(1, 1, n);
	while (q--) {
		int type, l, r;
		scanf("%d %d %d", &type, &l, &r);
		if (type == 1) 
			update(l, r);
		else
			printf("%d\n", query(l, r));
	}
	return 0;
}
			
