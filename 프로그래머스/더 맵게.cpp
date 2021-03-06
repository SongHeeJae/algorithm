#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    for(int cnt=0; !pq.empty() ; cnt++) {
        int t1 = pq.top(); pq.pop();
        if(t1 >= K) return cnt;
        if(pq.empty()) break;
        int t2 = pq.top(); pq.pop();
        pq.push(t1 + t2 * 2);
    }
    return -1;
}

/*
min heap으로 최소 스코빌 지수 음식 두 개를 계속 구해주었습니다
*/