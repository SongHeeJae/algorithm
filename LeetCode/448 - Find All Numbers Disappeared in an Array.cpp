/*
추가 공간 없이 O(n)의 런타임이라는 조건이 있었습니다.
수의 범위는 1~n이므로, 주어진 배열을 활용하여 방문 표시를 해주면 됩니다.
단, 방문 표시를 하되, 기존의 값을 기억할 수 있어야합니다.

방문한 수를 음수로 표시해두는 방법이 있었습니다.
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int num : nums) {
            int idx = abs(num) - 1;
            nums[idx] = -abs(nums[idx]);
        }
        
        vector<int> res;
        for(int i=0; i < nums.size(); i++) 
            if(nums[i] > 0) res.push_back(i + 1);
        return res;
    }
};


/*
방문한 수에 n을 계속 더해주는 방법도 있었습니다.
나머지 연산을 활용하면, 기존의 값을 알아낼 수 있습니다.
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int num : nums)
            nums[(num - 1) % n] += n;
        
        vector<int> res;
        for(int i=0; i < nums.size(); i++) 
            if(nums[i] <= n) res.push_back(i + 1);
        return res;
    }
};