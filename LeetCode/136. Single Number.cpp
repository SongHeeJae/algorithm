/*
모든 수를 xor 연산해주면, single number만 남게 됩니다.
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int num : nums) res ^= num;
        return res;
    }
};
