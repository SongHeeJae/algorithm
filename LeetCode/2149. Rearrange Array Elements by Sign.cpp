/*
nums를 순회하면서, 결과 배열에 양수와 음수를 순서에 맞게 삽입해주며 포인터를 업데이트해줍니다.
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res(nums.size());
        int i = 0, j = 1;
        for(int num : nums) {
            if(num > 0) res[i] = num, i += 2;
            else res[j] = num, j += 2;
        }
        return res;
    }
};
