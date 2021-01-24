#include <string>
#include <queue>
#include <vector>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    for(int i=0; i<works.size(); i++) pq.push(works[i]);
    while(n-- && pq.top() > 0) {
        pq.push(pq.top()-1);
        pq.pop();
    }
    while(!pq.empty()) {
        answer += pq.top() * pq.top();
        pq.pop();
    }
    return answer;
}

/*
pq를 이용해서 퇴근시간까지 최대 시간의 작업을 하나씩 업데이트해주었습니다.
*/