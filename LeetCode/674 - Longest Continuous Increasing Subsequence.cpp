/*
연속되는 증가하는 부분 수열의 길이와 최대 길이를 계속 업데이트해주면 됩니다.
*/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 1, val = 1;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] > nums[i - 1]) {
                val++;
            } else {
                ans = max(ans, val);
                val = 1;
            }
        }
        return max(ans, val);
    }
};
