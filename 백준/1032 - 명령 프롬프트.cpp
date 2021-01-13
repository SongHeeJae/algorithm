#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	int n;
	char f[51];
	scanf("%d", &n);
	scanf("%s", f, sizeof(f));
	while (--n) {
		char ff[51];
		scanf("%s", ff, sizeof(ff));
		for (int i = 0; i < strlen(ff); i ++ )
			f[i] = ff[i] != f[i] ? '?' : f[i];
	}

	printf("%s\n", f);
}