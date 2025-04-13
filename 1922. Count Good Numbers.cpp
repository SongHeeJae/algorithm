/*
짝수 인덱스는 0, 2, 4, 6, 8의 수가 들어갈 수 있고, 홀수 인덱스는 2, 3, 5, 7의 인덱스가 들어갈 수 있습니다.
즉, 길이 n만큼 5 * 4 * 5 * 4 ... 가 반복되므로, 5^((n + 1) / 2) * 4^(n / 2)를 구해주면 되는 것입니다.
pow 내장 함수를 이용하면 오버플로우가 발생할 수 있으므로, 분할정복으로 O(logN)의 시간을 가지면서 나머지 연산을 수행해주는 pow 함수를 직접 작성해줍니다.
*/

class Solution {
public:
    int MOD = 1000000007;

    int countGoodNumbers(long long n) {
        return powMod(5, (n + 1) / 2) * powMod(4, n / 2) % MOD;
    }

    long long powMod(int a, long long e) {
        if (e == 0) return 1;
        long long v = powMod(a, e / 2);
        return v * v * (e % 2 == 1 ? a : 1) % MOD;
    }
};
