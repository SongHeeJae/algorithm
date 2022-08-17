/*
dp를 이용하여 풀 수 있었습니다.
i번까지의 가장 긴 증가하는 부분수열의 길이를 업데이트해줍니다.
*/

class Solution {
public:
    int dp[10000];
    int lengthOfLIS(vector<int>& nums) {
        int res = 1;
        for(int i = 0; i<nums.size(); i++) {
            dp[i] = 1;
            for(int j=0; j<i; j++) {
                if(nums[i] > nums[j]) 
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

/*
다음과 같이 lower bound를 이용하여 풀 수도 있었습니다.
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        res.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= res.back())
                res[lowerBound(res, nums[i])] = nums[i];
            else res.push_back(nums[i]);
        }
        return res.size();
    }
    
    int lowerBound(vector<int>& res, int target) {
        int s = 0, e = res.size() - 1;
        while (s < e) {
            int mid = (s + e) / 2;
            if (res[mid] >= target) e = mid;
            else s = mid + 1;
        }
        return e;
    }
};
