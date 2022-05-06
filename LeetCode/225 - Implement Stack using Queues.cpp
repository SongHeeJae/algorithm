/*
하나의 큐를 이용하여 스택 구조를 만들어야했습니다.
마지막에 들어온 값을 큐의 가장 앞단에 위치시킬 수 있다면, 큐 하나로도 스택 구조를 유지할 수 있습니다.
삽입이 일어날 때마다 큐의 값들을 pop하고 다시 push 해주면 됩니다.
*/

class MyStack {
public:
    queue<int> q;
    
    MyStack() { }
    
    void push(int x) {
        q.push(x);
        int cnt = q.size() - 1;
        while(cnt--) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int t = q.front();
        q.pop();
        return t;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};