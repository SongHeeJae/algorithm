/*
nums를 정렬하고, 순차적으로 순회하며 prefix sum을 구해줍니다.
nums[i] < prefix sum 이라면, 최댓값을 업데이트해줍니다.
*/

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long mx = -1, cur = nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(cur > nums[i]) mx = max(mx, cur + nums[i]);
            cur += nums[i];
        }
        return mx;
    }
};
