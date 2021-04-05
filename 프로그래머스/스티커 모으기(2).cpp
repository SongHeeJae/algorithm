#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// dp[i][0]은 첫 스티커를 떼지 않은 경우 i번 째까지의 최대합
// dp[i][1]은 마지막 스티커를 떼지 않은 경우 i-1번 째까지의 최대합
int dp[100000][2];  
int solution(vector<int> sticker)
{
    int n = sticker.size();
    if(n == 1) return sticker[0];
    dp[0][0] = dp[0][1] = 0;
    dp[1][0] = sticker[1]; // 첫 스티커를 떼지 않았으니 두번째 스티커는 붙여야함
    dp[1][1] = sticker[0]; // 마지막 스티커를 떼지 않았으니 첫 번째 스티커는 붙여야함
    for(int i=2; i<n; i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-2][0] + sticker[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-2][1] + sticker[i-1]);
    }
    return max(dp[n-1][0], dp[n-1][1]);
}

/*
인접한 스티커를 연속으로 뗄 수는 없습니다.
원형이 아니라 일자 형태라고 생각한다면,
dp[i] = max(dp[i-1], dp[i-2] + sticker[i]); 로 정답을 구할 수 있을 것입니다.
하지만 원형이기 때문에, 첫 번째 스티커를 뗀다면, 마지막 스티커는 인접해있기 때문에 뗄 수 없습니다.

그렇다면, 첫 번째 스티커를 떼지 않는다면, 마지막 스티커는 신경 쓸 필요가 없습니다. 최댓값을 위해 두 번째 스티커는 꼭 떼어야할 것입니다.
그렇다면, 마지막 스티커를 떼지 않는다면, 최댓값을 위해 첫 번째 스티커는 떼어야합니다.

스티커를 떼지 않는 상황의 시작 지점을 달리하여, 첫 번째 스티커를 뗀 상황과 떼지 않은 상황에 대하여 최댓값을 각각 구해주었습니다. 
*/