/*
이진탐색과 투포인터를 이용하여 풀 수 있었습니다.
nums를 오름차순 정렬해줍니다.
nums를 순회하면서 기준점을 찾아주고, nums[i] + nums[j] + nums[k] == 0 (i < j < k < n)인 데이터를 찾아주면 됩니다.
j = i + 1, k = n - 1로 초기화하고,
nums[i] + nums[j] + nums[k] < 0이면, 합을 올려줘야하므로 좌측 포인터를,
nums[i] + nums[j] + nums[k] > 0이면, 합을 내려줘야하므로 우측 포인터를 이동합니다.
중복된 세 수는 필요 없으므로, 동일한 수는 건너뜁니다.
정렬했을 때,
첫 수가 0보다 큰 경우, 끝 수가 0보다 작은 경우, 세 수의 합은 0이 될 수 없습니다.
모든 수가 같은 경우(첫 수와 끝 수가 같은 경우), 모든 수가 0이라면 {0, 0, 0,}, 그렇지 않다면 세 수의 합은 0이 될 수 없습니다.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        if(nums.front() > 0) return {};
        if(nums.back() < 0) return {};

        if(nums.front() == nums.back()) {
            if(nums[0] == 0) return {{nums[0], nums[0], nums[0]}};
            else return {};
        }

        vector<vector<int>> res;
        for(int i=0; i<nums.size() - 2 && nums[i] <= 0; i++) {
            if(i > 0 && nums[i - 1] == nums[i]) continue;
            int l = i + 1, r = nums.size() - 1;
            while(l < r) {
                int s = nums[l] + nums[r] + nums[i];
                if(s == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    for(int cur = l; l < r && nums[l] == nums[cur]; l++);
                    for(int cur = r; l < r && nums[r] == nums[cur]; r--);
                } else if(s < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return res;
    }
};
