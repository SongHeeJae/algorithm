/*
nums의 모든 수를 xor해서 a ^ b를 구해줍니다.
a ^ b의 특정 비트가 1로 켜져있다면, a와 b의 해당 비트는 다릅니다.
해당 비트를 기준 삼아 두 그룹으로 분기하여 nums를 xor 해줍니다.
각 그룹에 대해 a와 b가 도출됩니다.
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int v = 0;
        for(int num : nums) {
            v ^= num;
        }

        int mask = 1;
        while(!(v & mask)) mask <<= 1;
        
        int res1 = 0, res2 = 0;
        for(int num : nums) {
            if(num & mask) res1 ^= num;
            else res2 ^= num;
        }
        return {res1, res2};
    }
};
