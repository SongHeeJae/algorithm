#include <iostream>
int buf[1000];
void merge(int* num, int len) {
	if (len < 2) return;
	int mid = len / 2;
	merge(num, mid);
	merge(num + mid, len - mid);
	int i = 0, j = mid, k = 0;
	while (i < mid && j < len)
		buf[k++] = num[i] < num[j] ? num[i++] : num[j++];
	while (i < mid) buf[k++] = num[i++];
	while (j < len) buf[k++] = num[j++];
	for (int i = 0; i < len; i++) num[i] = buf[i];
}

int main() {
	int n, num[1000], t = 0, s = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &num[i]);
	merge(num, n);
	for (int i = 0; i < n; i++) t += s += num[i];
	printf("%d\n", t);
}