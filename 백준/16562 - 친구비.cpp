#include <cstdio>

int n, m, k, a, b, ans = 0;
int cost[10001];
int p[10001];

int findParent(int x) {
	if (p[x] == x) return x;
	else return p[x] = findParent(p[x]);
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &cost[i]);
		p[i] = i;
	}
	while (m--) {
		scanf("%d %d", &a, &b);
		int pa = findParent(a);
		int pb = findParent(b);
		if (pa != pb) {
			if (cost[pa] < cost[pb]) p[pb] = pa;
			else p[pa] = pb;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (p[i] == i) ans += cost[i];
	}
	if (ans <= k) printf("%d", ans);
	else printf("Oh no");
}

/*
먼저 유니온파인드로 같은 친구 그룹을 묶어줍니다.
이 때, 비용이 더 저렴한 친구를 자신의 부모 노드로 설정해줍니다.
모든 친구의 부모 노드를 검사하면서, 자신이 최상위 루트인 친구를 사귀기 위한 비용을 더해줍니다.
*/