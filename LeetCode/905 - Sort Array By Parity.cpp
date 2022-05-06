/*
투포인터를 이용하여 풀었습니다.
짝수라면 왼쪽 포인터를 오른쪽으로 옮겨줍니다.
홀수라면 오른쪽 포인터를 왼쪽으로 옮겨줍니다.
왼쪽 포인터가 홀수를, 오른쪽 포인터가 짝수를 가리킬 때, 두 수를 스왑해줍니다.
*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(1) {
            while(l <= r && nums[l] % 2 == 0) l++;
            while(l <= r && nums[r] % 2 == 1) r--;
            if(l >= r) break;
            swap(nums[l++], nums[r--]);
        }
        return nums;
    }
};