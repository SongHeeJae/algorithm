/*
스택 구조를 이용하여 풀 수 있었습니다.
스택의 top에는 연속되는 문자의 개수를 기억해줍니다.
연속되는 문자가 k개라면, 스택에서 꺼내줍니다.
결국 스택에는 인접한 중복이 제거된 문자들만 남게 됩니다.
역순으로 검사하면 문자열의 순서도 유지해줄 수 있습니다. 
*/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stk;
        for(int i=s.size() - 1; i >= 0; i--) {
            if(!stk.empty() && stk.top().first == s[i])
                stk.top().second++;
            else 
                stk.push({s[i], 1});
            
            if(stk.top().second == k)
                stk.pop();
        }
        
        string result = "";
        while(!stk.empty()) {
            while(stk.top().second--)
                result.push_back(stk.top().first);
            stk.pop();
        }
        
        return result;
    }
};