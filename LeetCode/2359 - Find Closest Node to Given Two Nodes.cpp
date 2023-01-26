/*
BFS를 이용하여 풀 수 있었습니다.
node1과 node2를 큐에 넣어주고 BFS 수행해줍니다.
이미 방문한 노드를 다시 방문할 수 있을 때, 현재까지 구해진 거리보다 작거나 같은지 확인해줍니다.
그렇다면, 더 작은 인덱스 번호로 결과 노드를 업데이트해줍니다.
서로 연결되어 있는 노드인지 판별하기 위해,
node1은 양수로, node2는 음수로 거리(방문 여부)를 표기해주었습니다.
*/

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        if(node1 == node2) return node1;

        queue<int> q;
        int v[100001] = {0};
        int res = INT_MAX, dist = INT_MAX;

        q.push(node1);
        q.push(node2);

        v[node1] = 1;
        v[node2] = -1;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            int nxt = edges[node];
            if(nxt == -1) continue;
            if(v[nxt]) {
                if(v[node] * v[nxt] < 0 && dist >= abs(v[node])) {
                    // 부호가 다르고(같은 그룹), 더 가깝거나 동일한 거리(the smallest index)
                    dist = abs(v[node]);
                    res = min(res, nxt);
                }
                continue;
            }
            v[nxt] = (abs(v[node]) + 1) * (v[node] / abs(v[node]));
            q.push(nxt);
        }

        return res == INT_MAX ? -1 : res;
    }
};
