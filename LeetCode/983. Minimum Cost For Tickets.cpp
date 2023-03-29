/*
dp[i] = i번째 날의 최소 비용을 저장해줍니다.
dp[i] = min(
  dp[i - 1] + costs[0],
  dp[i - 7] + costs[1],
  dp[i - 30] + costs[2]
)
1/7/30일 전의 비용과 비교하면서, 동일한 티켓으로 여행할 수 있는 범위라면 최소 비용을 업데이트해줍니다.
*/

class Solution {
public:
    int dp[366] = {0};
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int idx = 0; 
        for(int i=1; i<=days.back(); i++) {
            if(i == days[idx]) {
                dp[i] = min({
                    dp[i - 1] + costs[0],
                    dp[max(0, i - 7)] + costs[1],
                    dp[max(0, i - 30)] + costs[2]
                });
                idx++;
            } else {
                dp[i] = dp[i - 1];
            }
        }
        
        return dp[days.back()];
    }
};
