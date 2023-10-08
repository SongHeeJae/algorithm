/*
두 배열에서 길이가 같은 서브시퀀스의 곱을 구하고, 그 합을 최대화해야합니다.
*/

class Solution {
public:
    int dp[500][500];

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, 0xbf, sizeof(dp));
        return maxDotProduct(nums1, 0, nums2, 0);
    }

    int maxDotProduct(vector<int>& nums1, int idx1, vector<int>& nums2, int idx2) {
        if(idx1 == nums1.size() || idx2 == nums2.size()) {
            return -1000000;
        }

        if(dp[idx1][idx2] != 0xbfbfbfbf) return dp[idx1][idx2];

        return dp[idx1][idx2] = max({
            nums1[idx1] * nums2[idx2],
            maxDotProduct(nums1, idx1, nums2, idx2 + 1),
            maxDotProduct(nums1, idx1 + 1, nums2, idx2),
            maxDotProduct(nums1, idx1 + 1, nums2, idx2 + 1) + nums1[idx1] * nums2[idx2]
        });
    }
};
