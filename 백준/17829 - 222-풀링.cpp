#include <iostream>
#include <algorithm>
int arr[1024][1024], n;
void f(int c) {
	if (c == n*2) return;
	f(c * 2);
	for (int i = 0; i < c; i += 2) {
		for (int j = 0; j < c; j += 2) {
			int t[4] = { arr[i][j], arr[i][j + 1], arr[i + 1][j], arr[i + 1][j + 1] };
			std::sort(t, t + 4);
			arr[i / 2][j / 2] = t[2];
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) scanf("%d", &arr[i][j]);
	f(1);
	printf("%d", arr[0][0]);
}