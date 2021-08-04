#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char a[1002], b[1002], c[1001];
int dp[1001][1001] = { 0 };

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

	int len = dp[al][bl];
	printf("%d\n", len);
	c[len] = '\0';
	while (len) {
		if (a[al] == b[bl]) {
			c[--len] = a[al];
			al--, bl--;
		}
		else {
			if (dp[al - 1][bl] > dp[al][bl - 1]) al--;
			else bl--;
		}
	}
	printf("%s", c);
}

/*
두 문자열이 a, b 라고 할 때,
dp[i][j] = a가 i번 인덱스까지, b가 j번 인덱스까지 나타났을 때의 최장 공통 부분 수열의 길이를 저장해줍니다.

a[i] == b[j] 일 때, 현재 문자를 포함시키면서 최장 공통 부분 수열의 길이를 하나 늘려줄 수 있으므로
dp[i][j] = dp[i - 1][j - 1] + 1;

a[i] != b[j] 일 때, 현재 문자를 최장 공통 부분 수열로 포함시킬 수 없으므로 이전까지 검사했던 최대 길이를 유지시켜줍니다.
dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

LCS 문자열은 dp를 완성시켜나갔던 과정을 역추적하며 구해주었습니다.
주어진 예제 입력을 예시로 들면, dp 테이블은 다음과 같이 완성됩니다.
  C A P C A K
A 0 1 1 1 1 1
C 1 1 1 2 2 2
A 1 2 2 2 3 3
Y 1 2 2 2 3 3
K 1 2 2 2 3 4
P 1 2 3 3 3 4

구하는 과정은 다음과 같습니다.
dp[6][6] -> dp[5][6] ( a[6] != b[6] 이고, dp[5][6] > dp[6][5]이므로 위에서 내려왔었음 )
dp[5][6] -> dp[4][5] ( a[5] == b[6] 이므로 LCS에 'K' 추가, 대각선으로 내려왔었음)
dp[4][5] -> dp[3][5] ( a[4] != b[5] 이고, dp[3][5] > dp[4][4]이므로 위에서 내려왔었음)
dp[3][5] -> dp[2][4] ( a[3] == b[5] 이므로 LCS에 'A' 추가, 대각선으로 내려왔었음)
dp[2][4] -> dp[1][3] ( a[2] == b[4] 이므로 LCS에 'C' 추가, 대각선으로 내려왔었음)
dp[1][3] -> dp[1][2] ( a[1] != b[3] 이고, dp[1][2] > dp[0][3]이므로 옆에서 넘어왔었음)
dp[1][2] -> dp[0][1] ( a[1] == b[2] 이므로 LCS에 'A' 추가, 대각선으로 내려왔었음)
종료
*/