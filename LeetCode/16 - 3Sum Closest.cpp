/*
정렬과 투포인터를 이용하여 풀 수 있었습니다.
하나의 수를 고정해놓고, 투포인터로 두 개의 수와 합을 구해줍니다.
수들의 합이 target 보다 작다면 좌측 포인터를,
수들의 합이 target 보다 크다면 우측 포인터를 옮겨줍니다.
그 과정에서 target에 가장 인접한 수들의 합을 구해줍니다.
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        for(int i=0; i<nums.size() - 2; i++) {
            int l = i + 1, r = nums.size() - 1;
            while(l < r) {
                int s = nums[i] + nums[l] + nums[r];
                if(abs(ans - target) > abs(s - target))
                    ans = s;
                
                if(s < target) l++;
                else if(s > target) r--;
                else return s;
            }
        }
        return ans;
    }
};
