/*
반드시 과반수인 요소가 있으므로, 선형 시간과 O(1)의 공간으로 처리하기 위해 Boyer–Moore majority vote 알고리즘을 이용하였습니다.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = 1, res = nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(c == 0) res = nums[i];
            c += res == nums[i] ? 1 : -1;
        }
        return res;
    }
};
