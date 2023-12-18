/*
가장 큰 2개의 값과 가장 작은 2개의 값을 찾아주면 됩니다.
정렬을 하면 O(nlogn)에 구할 수 있습니다.
*/

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - 1] * nums[nums.size() - 2] - nums[0] * nums[1];
    }
};

/*
nums를 순회하며 선형 시간에 구할 수도 있습니다.
*/

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int mx1 = 0, mx2 = 0, mn1 = INT_MAX, mn2 = INT_MAX;
        for(int num : nums) {
            if(mx1 < num) {
                mx2 = mx1;
                mx1 = num;
            } else if(mx2 < num) {
                mx2 = num;
            }

            if(mn1 > num) {
                mn2 = mn1;
                mn1 = num;
            } else if(mn2 > num) {
                mn2 = num;
            }
        }
        return (mx1 * mx2) - (mn1 * mn2);
    }
};
