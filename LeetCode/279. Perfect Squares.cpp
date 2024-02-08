/*
완전제곱수를 구해두고, n을 만들 수 있는 완전제곱수의 최소 개수를 구해줍니다.
*/

class Solution {
public:
    vector<int> s;
    int dp[10001] = {0};
    int numSquares(int n) {
        for(int i=1; i*i<=n; i++)
            s.push_back(i * i);
        return dfs(n);
    }

    int dfs(int n) {
        if(n == 0) return 0;
        else if(n < 0) return INT_MAX;

        if(dp[n]) return dp[n];

        dp[n] = INT_MAX;
        for(int i = s.size() - 1; i>=0; i--) {
            dp[n] = min(dp[n], dfs(n - s[i]));
        }
        return ++dp[n];
    }
};
