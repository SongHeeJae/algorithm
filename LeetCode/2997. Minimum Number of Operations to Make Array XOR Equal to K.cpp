/*
nums의 모든 수를 XOR 연산해줍니다.
그 결과와 k의 특정 비트가 다르다면, nums에서 아무 수의 해당 비트를 한 번 플립해주면 됩니다. 
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int v = 0;
        for(int num : nums) v ^= num;

        int res = 0;
        while(k || v) {
            if(k % 2 != v % 2) res++;
            k /= 2;
            v /= 2;
        }
        return res;
    }
};
