/*
배열에 nums1의 값 여부를 기록해두고, nums2를 순회하며 nums1에도 존재하는 값인지 확인해줍니다.
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        bool exist[1001] = {false};
        for(int num : nums1) exist[num] = true;
        vector<int> res;
        for(int num : nums2)
            if(exist[num]) {
                res.push_back(num);
                exist[num] = false; 
            }
        return res;
    }
};
