#include <cstdio>
char str[5][16] = { 0 };
int main() {
	for (int i = 0; i < 5; i++) scanf("%s", str[i]);
	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 5; j++)
			if (str[j][i]) printf("%c", str[j][i]);
}