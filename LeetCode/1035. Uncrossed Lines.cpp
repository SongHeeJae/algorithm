/*
교차하지 않는 연결 선의 최대 개수를 구하려면, 두 배열의 Longest Common Subsequence 길이를 구하면 됩니다.
*/

class Solution {
public:
    int dp[501][501] = {0};
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        for(int i=1; i<=nums1.size(); i++) {
            for(int j=1; j<=nums2.size(); j++) {
                dp[i][j] = nums1[i - 1] == nums2[j - 1] ? 
                    dp[i - 1][j - 1] + 1 :
                    max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[nums1.size()][nums2.size()];
    }
};
