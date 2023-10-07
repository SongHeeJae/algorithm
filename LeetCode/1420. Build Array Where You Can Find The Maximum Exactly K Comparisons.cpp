/*
1~m 범위의 수로 이루어진 n개의 배열을 만들어가면서, 1~n개의 배열에 대한 모든 경우를 탐색해주었습니다.
각 경우에 대해 최댓값을 기억하여 search_cost == k가 될 수 있는 배열의 개수를 구하고 재사용해주었습니다.
*/

class Solution {
public:
    int dp[51][101][51];

    int numOfArrays(int n, int m, int k) {
        memset(dp, -1, sizeof(dp));
        return numOfArrays(n, m, k, 0, 0);
    };

    int numOfArrays(int n, int m, int k, int idx, int maxValue) {
        if(n == idx) return k == 0;
        if(k < 0) return 0;

        int& c = dp[idx][maxValue][k]; 
        if(c != -1) return c;

        c = 0;
        for(int value = 1; value <= m; value++) {
            c += numOfArrays(n, m, k - (value > maxValue), idx + 1, max(value, maxValue));
            c %= 1000000007;
        }
        return c;
    }
};


