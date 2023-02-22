/*
이진 탐색 문제였습니다.
범위 내의 중간 인덱스 번호가 짝수일 때와 홀수일 때를 구분하고, 현재 값과 좌우의 값이 같은지 확인하여 범위를 좁혀나갈 수 있었습니다.
중간 인덱스 번호가 짝수일 때, 좌측 값과 같다면 좌측 범위에, 우측 값과 같다면 우측 범위에 single element가 있습니다.
중간 인덱스 번호가 홀수일 때, 우측 값과 같다면 좌측 범위에, 좌측 값과 같다면 우측 범위에 single element가 있습니다.
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, n = nums.size();
        while(l <= r) {
            int m = (l + r) / 2;
            if(m < n - 1 && nums[m] == nums[m + 1]) 
                m % 2 ? r = m - 1 : l = m + 1;
            else if(m > 0 && nums[m] == nums[m - 1])
                m % 2 ? l = m + 1 : r = m - 1;
            else
                return nums[m];
        }
        return -1;
    }
};
