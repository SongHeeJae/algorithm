#include <string>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

map<char, int> prio;
vector<int> expr;
long long ans = 0;

int getPriority(char ch) {
    return prio[ch];
}

void infixToPostfix(vector<int>& postfix) {
    stack<char> stk;
    for(int i=0; i<expr.size(); i++) {
        if(expr[i] < 0) {
            while(!stk.empty() && getPriority(stk.top()) >= getPriority(-expr[i])) {
                postfix.push_back(-stk.top());
                stk.pop();
            }
            stk.push(-expr[i]);
        } else {
            postfix.push_back(expr[i]);
        }
    }
    while(!stk.empty()) {
        postfix.push_back(-stk.top());
        stk.pop();
    }
}

long long eval(vector<int>& postfix) {
    stack<long long> stk;
    for(int i=0; i<postfix.size(); i++) {
        if(postfix[i] < 0) {
            long long second = stk.top();
            stk.pop();
            long long first = stk.top();
            stk.pop();
            if(-postfix[i] == '+') {
                stk.push(first + second);
            } else if(-postfix[i] == '-') {
                stk.push(first - second);
            } else {
                stk.push(first * second);
            }
        } else {
            stk.push(postfix[i]);
        }
    }
    return stk.top();
}

void calculate() {
    vector<int> postfix;
    infixToPostfix(postfix);
    ans = max(ans, abs(eval(postfix)));
}

void makePriority(vector<int>& num, vector<bool>& visit, int depth) {
    if(depth == num.size()) {
        int idx = 0;
        for(auto it = prio.begin(); it != prio.end(); it++) {
            it->second = num[idx++];
        }
        calculate();
        return;
    }
    for(int i=0; i<num.size(); i++) {
        if(visit[i]) continue;
        visit[i] = true;
        num[depth] = i;
        makePriority(num, visit, depth + 1);
        visit[i] = false;
    }
}

void solve() {
    vector<int> num(prio.size());
    vector<bool> visit(prio.size(), false);
    makePriority(num, visit, 0);
}

void initExpression(string& expression) {
    int idx = 0;
    for(int i=0; i<expression.size(); i++) {
        if(expression[i] < '0' || expression[i] > '9') {
            expr.push_back(stoi(expression.substr(idx, i)));
            expr.push_back(-expression[i]);
            prio.insert({expression[i], -1});
            idx = i + 1;
        }
    }
    expr.push_back(stoi(expression.substr(idx)));
}

long long solution(string expression) {
    initExpression(expression);
    solve();
    return ans;
}

/*
먼저 주어진 expression의 연산자와 피연산자를 분할해서 저장해주었습니다.
연산자는 음수 값으로 저장해서 연산자임을 표시하였습니다.
주어진 연산자의 중복을 제거하여 모든 연산자 우선순위의 쌍을 생성합니다.
각각의 연산자 우선순위의 쌍을 생성하면 스택을 이용하여 식을 계산해줍니다.
중위표기식으로 주어진 식을 후위표기식으로 변환해준 뒤, 후위표기식으로 변환된 식으로 결과값을 계산해주었습니다. 
*/