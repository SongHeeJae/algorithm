#include <iostream>
#include <map>
using namespace std;

map<int, int> set;
int n, m, a;
int graph[200][200];

int findParent(int x) {
	auto f = set.find(x);
	if (f == set.end()) return x;
	else return f->second = findParent(f->second);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a);
			if(a == 1) {
				int ai = findParent(i + 1);
				int aj = findParent(j + 1);
				if(ai != aj)
					set.insert({ ai, aj });
			}
		}
	}
	int p = -1, ans = 1;
	while (scanf("%d", &a) == 1) {
		if (p == -1) p = findParent(a);
		if (findParent(a) != p) ans = 0;
	}
	printf("%s\n", ans ? "YES" : "NO");
}

/*
갈 수 있는 경로라면, 같은 집합으로 묶어주었습니다.
이동 경로의 모든 조상이 같다면, 가능합니다.
*/