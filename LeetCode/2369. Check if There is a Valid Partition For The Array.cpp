/*
최대 3개 요소를 가지는 subarray만 확인하면 되므로, 마지막 3개 요소를 포함하는 파티션의 valid 여부를 재사용해주었습니다.
dp[i] =
  dp[i - 2] && satisfyCondOne() || // 마지막 2개 요소를 가지는 파티션의 조건1 valid 여부 && 그 이전 파티션들의 valid 여부
  dp[i - 3] && satisfyCondTwo() || // 마지막 3개 요소를 가지는 파티션의 조건2 valid 여부 && 그 이전 파티션들의 valid 여부
  dp[i - 3] && satisfyCondThree() // 마지막 3개 요소를 가지는 파티션의 조건3 valid 여부 && 그 이전 파티션들의 valid 여부
*/

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        if (n == 2)
            return satisfyCondOne(nums, 1);
        else if(n == 3)
            return satisfyCondTwo(nums, 2) || satisfyCondThree(nums, 2);

        bool dp[4] = {
            false,
            satisfyCondOne(nums, 1),
                satisfyCondTwo(nums, 2) ||
                satisfyCondThree(nums, 2)
        };

        for(int i=3; i<nums.size(); i++) {
            dp[i % 4] = 
                (dp[(i + 2) % 4] && satisfyCondOne(nums, i)) ||
                (dp[(i + 1) % 4] && satisfyCondTwo(nums, i)) ||
                (dp[(i + 1) % 4] && satisfyCondThree(nums, i));
        }

        return dp[(n + 3) % 4];
    }

    bool satisfyCondOne(vector<int>& nums, int i) {
        return nums[i] == nums[i - 1];
    }

    bool satisfyCondTwo(vector<int>& nums, int i) {
        return nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2];
    }

    bool satisfyCondThree(vector<int>& nums, int i) {
        return nums[i] - nums[i - 1] == 1 && nums[i - 1] - nums[i - 2] == 1;
    }
};


