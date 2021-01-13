#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const vector<string>& a, const vector<string>& b) {
    return a[1] < b[1];
}

bool dfs(const string& cur, vector<vector<string>>& tickets, vector<bool>& visit, vector<string>& answer) {
    answer.push_back(cur);
    if(answer.size() == tickets.size() + 1) {
        return true;
    }
    for(int i=0; i<tickets.size(); i++) {
        if(tickets[i][0] == cur && !visit[i]) {
            visit[i] = true;
            if(dfs(tickets[i][1], tickets, visit, answer)) return true;
            visit[i] = false;
        }
    }
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> visit(tickets.size(), false);
    sort(tickets.begin(), tickets.end(), compare);
    dfs("ICN", tickets, visit, answer);
    return answer;
}