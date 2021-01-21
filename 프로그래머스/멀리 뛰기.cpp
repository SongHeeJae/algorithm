#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int n) {
    int dp[2000] = {1,2};
    for(int i=2; i<n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 1234567;
    }
    return dp[n-1];
}

/*
dp[i] = i번째 칸에 도달할 수 있는 경우의 수
dp[1] = 1
dp[2] = 2로 초기화한 뒤에,
dp[i] = dp[i-1] + dp[i-2]
*/