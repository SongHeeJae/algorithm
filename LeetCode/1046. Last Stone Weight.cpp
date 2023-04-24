/*
우선순위 큐에 모든 돌을 넣어주고, 가장 무거운 2개의 돌 x와 y를 꺼내줍니다(x<=y).
두 돌의 무게가 다르다면, (y-x)를 다시 큐에 넣어줍니다.
돌이 1개 이하 남을 때 까지 반복합니다.
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int stone : stones) pq.push(stone);

        while(pq.size() > 1) {
            int y = pq.top(); pq.pop();
            int x = pq.top(); pq.pop();
            if(y > x) pq.push(y - x);
        }

        return pq.empty() ? 0 : pq.top();
    }
};
