#include <cstdio>
#define MAX 100001

int n, a, b, q, t, k;

int cnt[MAX] = { 0 };

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		cnt[a]++;
		cnt[b]++;
	}
	scanf("%d", &q);
	while (q--) {
		scanf("%d %d", &t, &k);
		if (t == 2) puts("yes");
		else {
			if (cnt[k] >= 2) puts("yes");
			else puts("no");
		}
	}
}

/*
N개의 정점이 N - 1개의 간선으로 연결된 트리 형태이므로, 모든 간선은 단절선이 됩니다.
주어진 간선을 양방향으로 봤을 때,
어떤 정점이 그래프의 끝에 있다면, 이 정점을 제거해도 그래프는 나뉘지 않습니다.
*/