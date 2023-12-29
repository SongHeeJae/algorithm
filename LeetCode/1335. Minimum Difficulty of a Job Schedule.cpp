class Solution {
public:
    int dp[300][11];

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        for(int i=0; i<jobDifficulty.size(); i++) 
            for(int j=1; j<=d; j++) dp[i][j] = INT_MAX;

        int res = minDifficulty(jobDifficulty, 0, d);
        return res != INT_MAX ? res : -1;
    }

    int minDifficulty(vector<int>& jobDifficulty, int idx, int d) {
        if(idx == jobDifficulty.size() && d == 0) {
            return 0;
        }

        if(idx == jobDifficulty.size() || d == 0) {
            return INT_MAX;
        }

        if(dp[idx][d] != INT_MAX) return dp[idx][d];
        
        int mx = 0;
        for(int i=idx; i<jobDifficulty.size(); i++) {
            mx = max(mx, jobDifficulty[i]);
            int res = minDifficulty(jobDifficulty, i + 1, d - 1);
            if(res != INT_MAX) {
                dp[idx][d] = min(dp[idx][d], mx + res);
            }
        }

        return dp[idx][d];
    }
};

