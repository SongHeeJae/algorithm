/*
각 stone에서 점프 크기(k)를 저장해줍니다.
이를 이용해서 다음으로 이동 가능한 stone과 해당 stone에서 점프 크기(k, k+1, k-1)를 다시 구해줍니다.
마지막 stone에 점프 크기가 저장되어있다면, 이전 stone에서 마지막 stone에 도달 가능했었음을 의미합니다.
*/

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> dp;
        dp[stones.front() + 1] = {1}; 
        for(int i=1; i<stones.size(); i++) {
            for(int jump : dp[stones[i]]) {
                dp[stones[i] + jump].insert(jump);
                dp[stones[i] + jump + 1].insert(jump + 1);
                dp[stones[i] + jump - 1].insert(jump - 1);
            }
        }
        return !dp[stones.back()].empty();
    }
};
