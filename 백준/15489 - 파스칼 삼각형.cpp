#include <cstdio>
int main() {
	int arr[30][30] = { 1 , }, r, c, w, s = 0;
	scanf("%d %d %d", &r, &c, &w);
	for (int i = 1; i < r + w - 1; i++) {
		arr[i][0] = arr[i - 1][0];
		for (int j = 1; j <= i; j++)
			arr[i][j] = arr[i - 1][j-1] + arr[i - 1][j];
	}
	for (int i = r - 1; i < r + w - 1; i++)
		for (int j = c - 1; j <= i - r + c; j++)
			s += arr[i][j];
	printf("%d\n", s);
}