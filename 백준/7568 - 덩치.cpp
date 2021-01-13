#include <cstdio>

void calRank(int p[][3], int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j && p[i][0] < p[j][0] && p[i][1] < p[j][1]) p[i][2]++;
}

int main() {
	int n;
	scanf("%d", &n);
	int persons[50][3] = { 0, };
	for (int i = 0; i < n; i++)
		scanf("%d %d", &persons[i][0], &persons[i][1]);

	calRank(persons, n);

	for (int i = 0; i < n; i++) printf("%d ", persons[i][2] + 1);
}