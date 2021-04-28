#include <cstdio>
#include <cstring>
#define INF 2147483647

int n, m, a, b, cnt;
int p[501], chk[501];

int findParent(int x) {
	if (p[x] == x) return x;
	else return p[x] = findParent(p[x]);
}

void init() {
	cnt = 0;
	memset(chk, 0, sizeof(chk));
	for (int i = 1; i <= n; i++) p[i] = i;
}

int main() {
	for (int idx = 1; scanf("%d %d", &n, &m) && n; idx++) {
		init();
		while (m-- && scanf("%d %d", &a, &b)) {
			int pa = findParent(a);
			int pb = findParent(b);
			if (pa != pb) {
				if (chk[pa] == -INF || chk[pb] == -INF) {
                    // 기존의 부모가 사이클이 있는 그룹였으면
                    // 새로운 노드도 트리가 되지 못하는 그룹에 속함
					chk[pa] = chk[pb] = -INF;
				}
				p[pa] = pb;
			}
			else chk[pa] = -INF; // 이미 같은 그룹이면 사이클 발생
		}
		for (int i = 1; i <= n; i++) chk[findParent(i)]++; // 그룹 중복 제거
		for (int i = 1; i <= n; i++)
			if (chk[i] > 0) cnt++; // 사이클 있는 그룹은 -INF이므로, 양수가 되지 못함
		printf("Case %d: ", idx);
		if (cnt == 0) printf("No trees.\n");
		else if (cnt == 1) printf("There is one tree.\n");
		else printf("A forest of %d trees.\n", cnt);
	}
}

/*
유니온 파인드로 트리인지 판별해주었습니다.
간선을 생성하는 두 노드의 부모가 같은 그룹이 아니라면, 같은 그룹으로 묶어줍니다.
이미 같은 그룹이라면, 사이클이 발생한 것입니다.
따라서 해당  부모 노드를 부모로 가지는 그룹은 트리를 구성할 수 없습니다.
또, 아직 같은 그룹이 아니더라도 이미 기존의 그룹이 사이클을 형성한 상태였으면, 새롭게 그룹에 들어오는 노드도 트리를 형성할 수 없는 그룹입니다. 
*/