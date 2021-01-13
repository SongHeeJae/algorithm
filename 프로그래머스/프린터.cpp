#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<int> q;
    for(int i=0; i<priorities.size(); i++) {
        q.push(i);
        pq.push(priorities[i]);
    }
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        if(priorities[x] == pq.top()) {
            answer++;
            if(x == location) break;
            pq.pop();
        } else {
            q.push(x);
        }
    }
    return answer;
}