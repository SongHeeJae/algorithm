/*
비트 연산을 이용하여 풀었습니다.
모든 수에 대해 각 비트를 검사해주면 됩니다.
각 비트에 대한 합이 3의 배수가 아니라면, single number에는 해당 비트가 있음을 의미합니다.
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i=0; i<32; i++) {
            int s = 0;
            for(int n : nums) s += (n >> i) & 1;
            res |= (s % 3) << i;
        }
        return res;
    }
};
