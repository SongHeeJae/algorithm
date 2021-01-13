#include <iostream>
#include <algorithm>
using namespace std;
int n, a[100000], dp[100000][2], s;
// dp[i][j]는 i번째에서의 누적합
// j == 0 i번째 수를 삭제하지않았을 때
// max(현재값, 이전 수까지의 누적합)
// j == 1 i번째 수를 삭제했을 때, 
// max(이전 수까지의 누적합, 이전 수를 삭제하지 않았을 때 + 현재 값)
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	s = dp[0][0] = a[0];
	dp[0][1] = 0;
	for (int i = 1; i < n; i++) 
	{	
		dp[i][0] = max(a[i], a[i] + dp[i - 1][0]);
		dp[i][1] = max(dp[i - 1][0], a[i] + dp[i-1][1]);
		s = max({ s, dp[i][0], dp[i][1] });
	}
	printf("%d", s);
}