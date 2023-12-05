/*
반복문을 이용해 로그 시간에 풀 수 있었습니다.
*/

class Solution {
public:
    int numberOfMatches(int n) {
        int res = 0;
        while(n > 1) {
            res += n / 2;
            n = n / 2 + n % 2;
        }
        return res;
    }
};

/*
상수 시간에 풀 수 있었습니다.
*/

class Solution {
public:
    int numberOfMatches(int n) {
        return n - 1;
    }
};
