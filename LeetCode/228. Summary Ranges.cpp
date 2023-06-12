/*
1의 차이로 연속된 구간을 하나로 묶어주었습니다.
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty()) return {};

        int s = nums[0], e = nums[0];
        vector<string> res;
        for(int n : nums) {
            if(n > e + 1) {
                res.push_back(s == e ? to_string(s) : to_string(s) + "->" + to_string(e));
                s = e = n;
            } else {
                e = n;
            }
        }
        res.push_back(s == e ? to_string(s) : to_string(s) + "->" + to_string(e));
        return res;
    }
};


