/*
unordered_map을 이용하면 O(n)에 해결할 수 있습니다.
num을 map에 초기화하면서, (target - num)이 이미 map에 있는지 판별해주면 됩니다.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size() == 2) return {0, 1};

        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++) {
            if(m.find(target - nums[i]) != m.end())
                return {m[target - nums[i]], i};
            m[nums[i]] = i;
        }
        return {};
    }
};
