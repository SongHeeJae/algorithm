/*
set에 모든 수를 초기화해주고, 이미 있는 수 인지 확인합니다.
*/

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());

        vector<int> res1, res2;
        for(int num : s1)
            if(s2.find(num) == s2.end()) res1.push_back(num);
        for(int num : s2)
            if(s1.find(num) == s1.end()) res2.push_back(num);

        return {res1, res2};
    }
};
