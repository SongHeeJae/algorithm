/*
모노토닉 스택 구조를 이용하여 풀 수 있었습니다.
스택의 top이 nums[i]보다 작다면, 스택에서 제거해줍니다.
모두 제거되었으면 nums[i]를 스택에 넣어줍니다.
그렇다면 스택에서 제거된 값들은, nums[i] 보다 작음을 의미합니다.
즉, 방금 스택에서 제거된 값들은 현재 스택의 top보다 작으므로, Pattern 32를 만족시킬 수 있던 상황입니다.
스택에서 제거된 값 중 가장 큰 값을 저장해줍니다. (스택은 내림차순을 유지하고 있었으므로 마지막에 pop된 값)
새롭게 만나는 수가 해당 값보다 작다면, 132 Pattern이 형성될 수 있음을 의미합니다.
*/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> stk;
        int val = INT_MIN;
        for(int i=nums.size() - 1; i>=0; i--) {
            if(nums[i] < val) return true;
            while(!stk.empty() && nums[i] > stk.top()) {
                val = stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};