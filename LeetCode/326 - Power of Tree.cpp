/*
수의 범위가 int 형이기 때문에,
2^31 - 1 이하에서 가장 큰 3의 제곱 수와 n의 나머지가 0이라면, 3의 제곱 수입니다.
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && !(1162261467 % n);
    }
};
