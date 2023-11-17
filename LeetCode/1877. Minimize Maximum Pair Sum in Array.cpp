/*
nums를 정렬하고, i번째 큰 값과 i번째 작은 값으로 쌍을 만들어줍니다.
*/

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i=0; i<nums.size(); i++) {
            res = max(res, nums[i] + nums[nums.size() - i - 1]);
        }
        return res;
    }
};


/*
n과 nums[i]은 최대 100000이기 때문에, 카운트 정렬을 이용하면 선형 시간에 풀 수 있었습니다.
*/

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int cnt[100001] = {0};
        for(int num : nums) cnt[num]++;
        int l = 1, r = 100000, res = 0;
        while(l <= r) {
            while(l <= r && cnt[l] <= 0) l++;
            while(l <= r && cnt[r] <= 0) r--;
            if(l > r) break;
            res = max(res, l + r);
            cnt[l]--, cnt[r]--;
        }
        return res;
    }
};
