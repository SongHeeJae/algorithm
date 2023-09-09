/*
target을 0으로 만드는 경우의 수를 재귀적으로 구하고, 중간 결과를 재활용 해주었습니다.
*/

class Solution {
public:
    int dp[1001];

    int combinationSum4(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return combination(nums, target);
    }

    int combination(vector<int>& nums, int target) {
        if(target == 0) return 1;
        if(target < 0) return 0;

        if(dp[target] != -1) return dp[target];
        dp[target] = 0;
        for(int n : nums) {
            dp[target] += combination(nums, target - n);
        }
        return dp[target];
    }
};
