class Solution {
public:
    vector<int> res, temp;
    int dp[1001] = {0};
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0, 1);
        return res;
    }

    void dfs(vector<int>& nums, int idx, int prv) {
        if(idx == nums.size()) {
            if(res.size() < temp.size()) res = temp;
            return;
        }

        int r = nums.size() - idx;
        if(temp.size() + r < res.size()) {
            return;
        }

        dfs(nums, idx + 1, prv);

        if (dp[idx] <= (int)temp.size() && nums[idx] % prv == 0) {
            temp.push_back(nums[idx]);
            dp[idx] = temp.size();
            dfs(nums, idx + 1, nums[idx]);
            temp.pop_back();
        }
    }
};
