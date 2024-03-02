/*
투포인터를 이용하면 선형 시간에 풀 수 있었습니다.
좌우측 포인터를 검사하며, 절댓값이 더 큰 값의 제곱 수를 배열에 기억해주고, 포인터를 이동해줍니다.
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        int l = 0, r = nums.size() - 1, idx = nums.size();
        while(idx--) {
            if(abs(nums[l]) < abs(nums[r])) {
                res[idx] = nums[r] * nums[r--];
            } else {
                res[idx] = nums[l] * nums[l++];
            }
        }
        return res;
    }
};
