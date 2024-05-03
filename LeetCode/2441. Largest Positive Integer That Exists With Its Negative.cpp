/*
각 수의 절댓값에 대해 특정 부호에 대한 값이 나왔는지 기억해주고, 다른 부호 값이 또 나오는지 확인해줍니다.
*/

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int val[1001] = {0}, res = -1;
        for(int num : nums) {
            int absNum = abs(num);
            if(val[absNum] == 0) {
                val[absNum] = num;
            } else if(val[absNum] != num) {
                res = max(res, absNum);
            }
        }
        return res;
    }
};

/*
정렬을 이용하면, 별도의 추가 공간 없이 투포인터로 풀 수 있습니다.
좌측 포인터가 0 초과, 우측 포인터가 0 미만이면, 원하는 수를 찾을 수 없습니다.
*/

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        while(l < r && nums[l] < 0 && nums[r] > 0) {
            if(-nums[l] == nums[r]) return nums[r];
            else if(-nums[l] > nums[r]) l++;
            else r--;
        }
        return -1;
    }
};
