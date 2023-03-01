/*
로그 시간에 들어오면 되는 정렬 문제였습니다.
병합 정렬로 풀어주었습니다.
*/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        msort(nums, 0, nums.size() - 1);
        return nums;
    }
private:
    void msort(vector<int>& nums, int l, int r) {
        if(l >= r) return;
        int m = (l + r) / 2;
        msort(nums, l, m);
        msort(nums, m + 1, r);

        vector<int> buf(r - l + 1);
        int i = l, j = m + 1, k = 0;
        while(i <= m && j <= r) {
            buf[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++]; 
        }

        while(i <= m) {
            buf[k++] = nums[i++];
        }

        while(j <= r) {
            buf[k++] = nums[j++];
        }

        for(k=l; k<=r; k++) {
            nums[k] = buf[k - l];
        }
    }
};
