/*
탑다운 방식으로 풀었습니다.
dp[r][c] = min({dp[r + 1][c - 1], dp[r + 1][c], dp[r + 1][c + 1]}) + matrix[r][c]
*/

class Solution {
public:
    int dp[100][100];

    int minFallingPathSum(vector<vector<int>>& matrix) {
        memset(dp, 0x77, sizeof(dp));
        int res = INT_MAX;
        for(int i=0; i<matrix.size(); i++) {
            res = min(res, minFallingPathSum(matrix, 0, i));
        }
        return res;
    }

    int minFallingPathSum(vector<vector<int>>& matrix, int r, int c) {
        if(r == matrix.size()) return 0;
        if(c < 0 || c >= matrix.size()) return 100000;

        if(dp[r][c] != 0x77777777) return dp[r][c];

        return dp[r][c] = min({
            minFallingPathSum(matrix, r + 1, c - 1),
            minFallingPathSum(matrix, r + 1, c),
            minFallingPathSum(matrix, r + 1, c + 1),
        }) + matrix[r][c];
    }
};

/*
바텀업 방식으로 변환하였습니다.
dp[r][c] = min({dp[r - 1][c - 1], dp[r - 1][c], dp[r - 1][c + 1]}) + matrix[r][c]
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=1; i<n; i++) {
            for(int j=0; j<n; j++) {
                int s = INT_MAX;
                if(j > 0) s = min(s, matrix[i - 1][j - 1]);
                s = min(s, matrix[i - 1][j]);
                if(j < n - 1) s = min(s, matrix[i - 1][j + 1]);
                matrix[i][j] += s;
            }
        }

        int res = INT_MAX;
        for(int i=0; i<n; i++) {
            res = min(res, matrix[n - 1][i]);
        }
        return res;
    }
};


