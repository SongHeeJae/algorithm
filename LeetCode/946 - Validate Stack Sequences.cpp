class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int j = 0;
        for(int i=0;i<pushed.size(); i++) {
            stk.push(pushed[i]);
            while(!stk.empty() && stk.top() == popped[j]) {
                stk.pop();
                j++;
            }
        }
        return stk.empty();
    }
    
};

/*
스택으로 push와 pop 연산을 수행하며 풀 수 있었습니다.
pushed의 요소를 순회하며 스택에 push 해줍니다.
이 때, 스택의 top이 popped의 현재 요소와 일치하면 pop 해줍니다. 동시에 popped의 다음 요소를 바라보고 반복합니다.
해당 과정이 끝난 뒤 스택이 비어있으면, 주어진 pushed 배열의 push와 pop 연산으로 popped 배열 순서를 만들어낼 수 있음을 의미합니다.
*/