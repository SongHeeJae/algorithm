#include <cstdio>
int n, i, j, k;
char star[2200][2200] = { "***","* *", "***" };
void drawStar(int c) {
	if (c == n) return;
	for (k=c*3, i = 0; i < k; i++)
		for (j = 0; j < k; j++) star[i][j] = star[i % c][j % c];
	for (k = c * 2, i = c; i < k; i++)
		for (j = c; j < k; j++) star[i][j] = ' ';
	drawStar(c*3);
}
int main() {
	scanf("%d", &n);
	drawStar(3);
	for (int i = 0; i < n; i++) puts(star[i]);
}


/*

#include <cstdio>
int n, i, j, k;
char star[2200][2200] = { "***","* *", "***" };
void drawStar(int c) {
	if (c == n) return;
	for (k=c*3, i = 0; i < k; i++)
		for (j = 0; j < k; j++) star[i][j] = i / c == 1 && j / c == 1 ? ' ' : star[i % c][j % c];
	drawStar(k);
}
int main() {
	scanf("%d", &n);
	drawStar(3);
	for (int i = 0; i < n; i++) puts(star[i]);
}

*/