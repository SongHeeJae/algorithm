#include <iostream>
int main() {
	int n, a;
	char c;
	scanf("%d", &n);
	getchar();
	while (n--) {
		a = 0;
		while ((c = getchar()) != '\n') c == '(' ? a++ : (a != 0 ? a-- : a=99);
		printf("%s\n", a==0 ? "YES" : "NO");
	}
}