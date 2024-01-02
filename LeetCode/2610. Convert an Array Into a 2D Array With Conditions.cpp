/*
각 row에서 중복 수가 나오면 안되므로, 별도 row로 처리해주면 됩니다.
각 수가 나온 횟수를 기억하고, 중복 수가 나오면 새로운 row를 만들어줍니다. 
*/

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> cnt(nums.size() + 1, 0);
        vector<vector<int>> res;
        for(int num : nums) {
            if(res.size() <= cnt[num]) {
                res.push_back({});
            }
            res[cnt[num]++].push_back(num);
        }
        return res;
    }
};

