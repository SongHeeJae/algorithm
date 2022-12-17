/*
스택에 피연산자를 담아주다가, 연산자를 만나면 수행된 결과를 삽입해줍니다.
*/

typedef long long ll;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<ll> stk;
        for(string& token : tokens)
            stk.push(isOperator(token) ? operate(token, pop(stk), pop(stk)) : stoi(token));
        return stk.top();
    }

private:
    bool isOperator(string& token) {
        return token == "+" || token == "-" || token == "/" || token == "*";
    }

    ll operate(string& op, ll b, ll a) {
        if(op == "+") return a + b;
        else if(op == "-") return a - b;
        else if(op == "*") return a * b;
        else return a / b;
    }

    ll pop(stack<ll>& stk) {
        ll top = stk.top();
        stk.pop();
        return top;
    }
};
