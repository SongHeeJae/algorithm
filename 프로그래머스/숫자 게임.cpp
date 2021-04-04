#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    priority_queue<int> aq, bq;
    for(int i=0; i<A.size(); i++) aq.push(A[i]), bq.push(B[i]);
    while(!aq.empty()) {
        if(bq.top() > aq.top()) bq.pop();
        aq.pop();
    }
    return A.size() - bq.size();
}

/*
B가 A보다 최소한으로 큰 경우에만 점수로 인정해줄 것입니다.
먼저 최대 힙에 A와 B의 모든 값을 담아줍니다.
현재 B에 있는 최댓값이 A의 최댓값을 이길 수 있다면, 점수를 가져갑니다.
현재 B에 있는 최댓값이 A의 최댓값을 이길 수 없다면, 그 게임은 그냥 지는 것으로 하고, A의 다음 최댓값과 승부를 봅니다. 
B가 담긴 최대 힙에 남아있는 요소의 개수가 패배한 횟수입니다.
*/