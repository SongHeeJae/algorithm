#include <cstdio>

char func[100001], ch;
int t, n, arr[100000], s, e, f;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%s %d %c", func, &n, &ch);
		for (int i = 0; i < n && scanf("%d %c", &arr[i], &ch); i++);
		if (n == 0) scanf(" %c", &ch);
		s = 0, e = n - 1, f = 1;
		for (int i = 0; func[i] != '\0'; i++) {
			if (func[i] == 'R') f = !f;
			else {
				if (s > e) {
					s = -1;
					break;
				}
				if (f) s++;
				else e--;
			}
		}
		if (s == -1) printf("error\n");
		else if (n == 0 || s > e) printf("[]\n");
		else {
			printf("[%d", f ? arr[s] : arr[e]);
			if (f) {
				for (int i = s + 1; i <= e; i++) printf(",%d", arr[i]);
			}
			else {
				for (int i = e - 1; i >= s; i--) printf(",%d", arr[i]);
			}
			printf("]\n");
		}
	}
}