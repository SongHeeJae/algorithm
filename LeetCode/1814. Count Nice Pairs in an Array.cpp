/*
nums[i] - rev(nums[i]) == nums[j] + rev(nums[j])를 검사해주면 됩니다.
nums를 순회하면서 nums[i] - rev(nums[i]) 값이 나온 개수를 구해주고,
nums[i] - rev(nums[i]) 값이 나온 개수를 하나 올려줍니다.
순차적으로 검사하기 때문에, i < j와 위 조건을 만족하는 pair의 개수를 구할 수 있습니다.
*/

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int res = 0;
        for(int num : nums) {
            int revNum = rev(num);
            res = (res + cnt[num - revNum]++) % 1000000007;
        }
        return res;
    }
private:
    int rev(int num) {
        int res = 0;
        while(num) {
            res = res * 10 + num % 10;
            num /= 10;
        }
        return res;
    }
};
