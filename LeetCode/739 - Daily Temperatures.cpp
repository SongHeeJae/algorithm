/*
스택에 인덱스를 담아줍니다.
지금 탐색하는 온도가 스택에 담긴 날(인덱스)보다 따뜻하다면, 인덱스 차를 계산해줍니다.
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());
        stack<int> stk;
        for(int i=0; i<temperatures.size(); i++) {
        while(!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
                result[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return result;
    }
};



