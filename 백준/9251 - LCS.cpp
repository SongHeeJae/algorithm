#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char a[1002], b[1002];
int dp[1001][1001] = {0};

int main() {
	scanf("%s %s", a + 1, b + 1);
	int al = strlen(a + 1);
	int bl = strlen(b + 1);
	for (int i = 1; i <= al; i++) {
		for (int j = 1; j <= bl; j++) {
			if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	printf("%d\n", dp[al][bl]);
}

/*
풀이는 다음과 같습니다.
https://blog.naver.com/gmlwo308/222455459132
*/