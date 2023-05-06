class Solution {
public:
    const int MOD = 1e9 + 7;
    int pow2[100001] = {1};

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1, res = 0;
        for(int i=1; i<=nums.size(); i++)
            pow2[i] = (pow2[i - 1] << 1) % MOD;

        while(l <= r) {
            if(nums[l] + nums[r] <= target) {
                res = (res + pow2[r - l]) % MOD;
                l++;
            }
            else {
                r--;
            }
        }
        return res;
    }
};
