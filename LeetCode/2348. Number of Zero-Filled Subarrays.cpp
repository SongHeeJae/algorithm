/*
연속된 0의 개수를 구하여, 0으로 채워진 subarray 개수를 구해줍니다.
*/

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int c = 0;
        long long res = 0;
        for(int num : nums) {
            if(num == 0) {
                res += ++c;
            } else {
                c = 0;
            }
        }
        return res;
    }
};
