/*
dp[i] = i번째에 도달할 때의 최소합을 저장해줍니다.
1칸 또는 2칸씩만 점프할 수 있으므로
dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i] 이 됩니다.
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for(int i=2; i<cost.size(); i++)
            cost[i] = min({cost[i - 1], cost[i - 2]}) + cost[i];
        return min(cost[cost.size() - 1], cost[cost.size() - 2]);
    }
};
