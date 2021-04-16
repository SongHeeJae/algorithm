#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> stk;
    stk.push(s[0]);
    for(int i=1; i<s.size(); i++) {
        if(!stk.empty() && stk.top() == s[i]) stk.pop();
        else stk.push(s[i]);
    }
    return stk.empty();
}

/*
스택 구조를 이용해서 풀었습니다.
현재 문자와 스택의 탑이 같다면 pop, 다르다면 push해줍니다.
스택이 비어있으면 모든 문자가 제거된 것입니다.
*/