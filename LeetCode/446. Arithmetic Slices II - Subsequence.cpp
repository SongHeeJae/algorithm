class Solution {
public:
    unordered_map<int, int> dp[1001];
    int numberOfArithmeticSlices(vector<int>& nums) {
        int c = 0;
        for(int i=1; i<nums.size(); i++) {
            for(int j=0; j<i; j++) {
                long diffLong = (long)nums[j] - nums[i];
                if (diffLong < INT_MIN || diffLong > INT_MAX) continue;

                int diff = diffLong;
                int cnt = dp[j][diff];
                dp[i][diff] += cnt + 1;
                c += cnt;
            }
        }
        return c;
    }
};
