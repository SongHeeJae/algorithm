/*
vector에 history를 저장하면서, 연산에 의한 history 포인터를 관리해주었습니다.
visit 시에 forward history가 정리될 수 있음을 나타내면 됩니다.
*/

class BrowserHistory {
public:
    vector<string> history;
    int cur = 0, mx = 0;
    BrowserHistory(string homepage) {
        history.push_back(homepage);
    }
    
    void visit(string url) {
        mx = ++cur;
        if(cur < history.size()) {
            history[cur] = url;
        } else {
            history.push_back(url);
        }
    }
    
    string back(int steps) {
        cur = max(0, cur - steps);
        return history[cur];
    }
    
    string forward(int steps) {
        cur = min(mx, cur + steps);
        return history[cur];
    }
};
