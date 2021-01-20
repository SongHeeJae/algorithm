#include <string>
#include <vector>
#include <queue>
#include <cstdlib>
#include <iostream>
using namespace std;

int deleteOperation(priority_queue<pair<int, int>>& pq, vector<bool>& visit, int type, bool v = true) {
    while(!pq.empty()) {
        int topVal = pq.top().first * type;
        int topIdx = pq.top().second;
        pq.pop();
        if(!visit[topIdx]) {
            visit[topIdx] = v;
            return topVal;
        }
    }
    return 0;
}

vector<int> solution(vector<string> operations) {
    vector<bool> visit(operations.size(), false);
    vector<int> answer(2, 0);
    priority_queue<pair<int, int>> pq1; // max heqp
    priority_queue<pair<int, int>> pq2; // min heqp
    for(int i=0; i<operations.size(); i++) {
        string op = operations[i];
        if(op[0] == 'I') {
            int val = atoi(op.substr(2).c_str());
            pq1.push({val, i});
            pq2.push({-val, i});
        } else {
            if(op[2] == '1') deleteOperation(pq1, visit, 1);
            else deleteOperation(pq2, visit, -1);
        }
    }
    answer[0] = deleteOperation(pq1, visit, 1, false);
    answer[1] = deleteOperation(pq2, visit, -1, false);
    return answer;
}

/*
max heap과 min heap을 두고, 이미 삭제한 인덱스 번호에 대해서는 방문 처리를 해주었습니다.

방문하지 않은 값들 중에서 최종적으로 max heap의 남은 값과 min heap의 남은 값이 정답입니다.
*/