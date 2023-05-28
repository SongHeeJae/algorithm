/*
cuts에 0과 n을 넣고 오름차순으로 정렬해줍니다.
dp[l][r] = cuts[l]과 cuts[r] 범위를 컷할 때의 최소 비용을 구해줍니다. (r - l > 1)
cuts[r] - cuts[l]이 범위를 컷하는 비용이 되고, 범위 내의 다른 컷들을 재귀적으로 수행해줍니다.
*/

class Solution {
public:
    int dp[102][102] = {0};
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        return dfs(cuts, 0, cuts.size() - 1);
    }

    int dfs(vector<int>& c, int l, int r) {
        if(r - l <= 1) {
            return 0;
        }

        if(dp[l][r]) {
            return dp[l][r];
        }

        int cost = c[r] - c[l];
        dp[l][r] = INT_MAX;
        for(int i = l + 1; i < r; i++) {
            dp[l][r] = min(dp[l][r], cost + dfs(c, l, i) + dfs(c, i, r));
        }

        return dp[l][r];
    }
};
