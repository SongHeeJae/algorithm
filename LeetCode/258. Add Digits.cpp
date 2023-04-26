/*
반복문을 이용하여 num이 한 자릿수가 될 때까지 연산을 수행하였습니다.
*/

class Solution {
public:
    int addDigits(int num) {
        int res = num;
        while(res >= 10) {
            int s = 0;
            while(res) {
                s+=res%10, res/=10;
            }
            res = s;
        }
        return res;
    }
};
