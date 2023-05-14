/*
nums의 두 수 nums[i], nums[j]를 선택해가는 경로에서 얻을 수 있는 최대 점수를 기억해줍니다.
2^(nums.size)개의 경우의 수를 나타내기 위해 비트마스킹을 이용하였습니다.
*/

class Solution {
public:
    int dp[1 << 14] = {0};

    int maxScore(vector<int>& nums) {
        return dfs(nums, 1, 0);
    }

    int dfs(vector<int>& nums, int cnt, int visit) {
        if(visit == (1 << nums.size())) return 0;

        int& score = dp[visit];
        if(score) return score;

        for(int i = 0; i < nums.size(); i++) {
            if((visit >> i) & 1) continue;
            for(int j = i + 1; j < nums.size(); j++) {
                if((visit >> j) & 1) continue;
                int nextVisit = visit | (1 << i) | (1 << j);
                score = max(
                    score, 
                    cnt * gcd(nums[i], nums[j]) + dfs(nums, cnt + 1, nextVisit)
                );
            }
        }

        return score;
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b); 
    }
};
