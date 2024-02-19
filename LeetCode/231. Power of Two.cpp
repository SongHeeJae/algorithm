/*
2의 제곱 수라면 비트가 1개만 켜져있으므로, n & (n-1)의 결과는 0이 됩니다.
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n & (n - 1));
    }
};
