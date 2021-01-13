#include <cstdio>
int n, m, k, idx;
int p[20][3] = { 0, }; // 학생번호, 추천수, 게시 시점
int findEmptySpace() {
	for (int i = 0; i < n; i++)
		if (p[i][0] == 0) return i;
	return -1;
}

int isFilled(int k) {
	for (int i = 0; i < n; i++)
		if (p[i][0] == k) return i;
	return -1;
}

int findDeletableSpace() {
	int idx = 0;
	for (int i = 1; i < n; i++)
		if (p[i][1] < p[idx][1]) idx = i;
	for (int i = 0; i < n; i++)
		if (p[i][1] == p[idx][1] && p[i][2] < p[idx][2]) idx = i;
	return idx;
}

void qsort(int l, int r) {
	if (l >= r) return;
	int s = l - 1;
	int e = r + 1;
	int pv = p[(s+e)/2][0];
	while (1) {
		while (p[++s][0] < pv);
		while (p[--e][0] > pv);
		if (s >= e) break;
		int temp = p[s][0];
		p[s][0] = p[e][0];
		p[e][0] = temp;
	}
	qsort(l, s - 1);
	qsort(e + 1, r);
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &k);
		idx = isFilled(k);
		if (idx != -1) p[idx][1]++;
		else {
			idx = findEmptySpace();
			if (idx == -1) idx = findDeletableSpace();
			p[idx][1] = 1;
			p[idx][0] = k;
			p[idx][2] = i;
		}
	}
	qsort(0, n - 1);
	for (int i = 0; i < n; i++) printf("%d ", p[i][0]);
}

/*
이미 사진틀에 채워진 학생이면 추천수를 증가시키고,

그게 아니라면, 빈 공간 또는 삭제 가능한 위치를 찾아줬습니다.
*/