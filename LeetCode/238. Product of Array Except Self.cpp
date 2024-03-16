/*
O(1)의 공간으로 나눗셈 연산 없이 해결해야 합니다.
i번째를 제외한 좌/우측의 prefix product를 구해주면 됩니다.
res[i] = 좌_prefix_product[i] * 우_prefix_product[i]
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        
        int left = 1;
        for(int i=0; i<nums.size(); i++) {
            res[i] = left;
            left *= nums[i];
        }

        int right = 1;
        for(int i=res.size() - 1; i>=0; i--) {
            res[i] *= right;
            right *= nums[i];
        }

        return res;
    }
};
