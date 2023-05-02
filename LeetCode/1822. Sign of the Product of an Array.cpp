/*
음수가 나오면 부호를 바꿔줍니다.
*/

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int res = 1;
        for(int num : nums) {
            if(!num) return 0;
            if(num < 0) res = -res;
        }
        return res;
    }
};
