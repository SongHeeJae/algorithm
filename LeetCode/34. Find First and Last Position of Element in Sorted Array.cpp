/*
lower bound와 upper bound를 이용하여 first, last 포지션을 로그 시간에 찾을 수 있었습니다.
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lowerBound(nums, target);
        int last = upperBound(nums, target) - 1;

        return {
            first >= 0 && nums[first] == target ? first : -1,
            last >= 0 && nums[last] == target ? last : -1
        };
    }

    int lowerBound(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        while(s < e) {
            int m = (s + e) / 2;
            if(nums[m] >= target) e = m;
            else s = m + 1;
        }
        return e;
    }

    int upperBound(vector<int>& nums, int target) {
        int s = 0, e = nums.size();
        while(s < e) {
            int m = (s + e) / 2;
            if(nums[m] > target) e = m;
            else s = m + 1;
        }
        return e;
    }
};



/*
이미 구해진 first를 이용하여 더욱 최적화할 수 있었습니다.
target이 있음을 재차 확인하는 과정을 없애고, upper bound를 재수행해야하는 범위를 좁힐 수 있었습니다.
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lowerBound(nums, target);
        if (first < 0 || nums[first] != target){
            return {-1, -1};
        }
        int last = upperBound(nums, target, first, nums.size()) - 1;
        return { first, last };
    }

    int lowerBound(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        while(s < e) {
            int m = (s + e) / 2;
            if(nums[m] >= target) e = m;
            else s = m + 1;
        }
        return e;
    }

    int upperBound(vector<int>& nums, int target, int s, int e) {
        while(s < e) {
            int m = (s + e) / 2;
            if(nums[m] > target) e = m;
            else s = m + 1;
        }
        return e;
    }
};


