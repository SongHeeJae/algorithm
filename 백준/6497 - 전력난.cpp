#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int m, n, x, y, z, maxSum, sum, p[200000];
vector<int> edges[200000];
int findParent(int x) {
	if (p[x] == x) return x;
	else return p[x] = findParent(p[x]);
}
int main() {
	while (1) {
		scanf("%d %d", &m, &n);
		maxSum = sum = 0;
		for (int i = 0; i < m; i++) p[i] = i;
		if (m == 0) break;
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &x, &y, &z);
			edges[i] = { z, x, y };
			maxSum += z;
		}
		sort(edges, edges + n);
		for (int i = 0; i < n; i++) {
			int pa = findParent(edges[i][1]);
			int pb = findParent(edges[i][2]);
			if (pa != pb) {
				p[pa] = pb;
				sum += edges[i][0];
			}
		}
		printf("%d\n", maxSum - sum);
	}
}

/*
모든 집을 연결할 수 있는 최소 길이 합을 구하여 절약할 수 있는 최대 비용을 구해주었습니다. 
*/