/*
오름차순으로 이동될 수 있는 경로를 모두 탐색해주었습니다.
*/

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> result;
        vector<int> temp;

        for(int i=0; i<nums.size(); i++)
            dfs(i, nums, temp, result);
        
        return vector<vector<int>>(result.begin(), result.end());
    }

    void dfs(int idx, vector<int>& nums, vector<int>& temp, set<vector<int>>& result) {
        temp.push_back(nums[idx]);

        if(temp.size() > 1) result.insert(temp);
        
        for(int i = idx + 1; i<nums.size(); i++)
            if(nums[idx] <= nums[i])
                dfs(i, nums, temp, result);

        temp.pop_back();
    }
};
