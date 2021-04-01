#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

char buf[11];
int n, alp1[26] = { 0 }, alp2[26] = { 0 }, ans = 0, diff;

void init(char* s, int* alp) {
	for (int i = 0; i < strlen(s); i++) alp[s[i] - 'A']++;
}

int main() {
	scanf("%d %s", &n, buf);
	init(buf, alp1);
	int blen = strlen(buf);
	while (--n && scanf("%s", buf)) {
		memset(alp2, 0, sizeof(alp2));
		init(buf, alp2);
		diff = 0;
		for (int i = 0; i < 26; i++) diff += abs(alp1[i] - alp2[i]);
		if (diff < (blen == strlen(buf) ? 3 : 2)) ans++;
	}
	printf("%d", ans);
}

/*
먼저 두 단어의 알파벳 개수를 초기화해주고, 각 알파벳 개수의 차이의 합을 구해줍니다.
길이가 같을 때는, 차이가 2 이하라면 비슷한 단어입니다. (1개 치환하면, 2만큼 차이)
길이가 다를 때는, 차이가 1 이하라면 비슷한 단어입니다.
*/