/*
n까지의 합을 구하고, nums의 모든 합을 빼주면, 사라진 수를 찾을 수 있습니다.
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s = 0;
        for(int num : nums) s += num;
        return nums.size() * (nums.size() + 1) / 2 - s;
    }
};
