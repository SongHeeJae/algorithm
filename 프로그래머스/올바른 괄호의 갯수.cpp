#include <string>
#include <vector>

using namespace std;

int dp[15] = {1,1, 2};

int solution(int n) {
    for(int i=3; i<=n; i++) {
        for(int j=0; j<i; j++) {
            dp[i] += dp[j] * dp[i-1-j];
        }
    }
    return dp[n];
}