/*
먼저 이진 탐색으로 회전이 일어난 피벗 인덱스를 찾아줍니다.
피벗 인덱스를 통해 회전되기 이전의 인덱스를 찾을 수 있습니다. ((idx + pivot) % nums.length)
이를 이용하여 target이 있는지 이진 탐색을 수행해줍니다.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int m = (l + r) / 2;
            if(nums[m] > nums[r]) l = m + 1;
            else r = m;
        }
        
        int pivot = r;
        l = 0, r = nums.size() - 1;
        while(l <= r) {
            int m = (l + r) / 2;
            int rm = (m + pivot) % nums.size();
            if(nums[rm] == target) return rm;
            if(nums[rm] < target) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }
};
