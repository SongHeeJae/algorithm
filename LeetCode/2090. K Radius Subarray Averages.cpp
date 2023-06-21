/*
k번째의 k radius subarray sum을 초기화해두고, 순차적으로 탐색하면서 다음 sum을 업데이트해주었습니다.
*/

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k == 0) return nums;

        int n = nums.size();
        long long s = 0;
        for(int i=1; i<min(n, k*2); i++)
            s += nums[i];

        vector<int> res(nums.size(), -1);
        for(int i=k; i<n-k; i++) {
            s += nums[i - k] + nums[i + k];
            res[i] = s / (k*2+1);
            s -= nums[i - k] + nums[i - k + 1];
        }
        return res;
    }
};
