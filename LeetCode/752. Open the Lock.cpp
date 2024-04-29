/*
"0000"부터 target에 도달할 수 있을 때까지 BFS를 수행해주면 됩니다.
0~9999까지의 integer 값으로 변환 및 초기화하여 수행해주었습니다.
*/

class Solution {
public:
    bool visit[10000] = {false};
    bool deadend[10000] = {false};
    int r[4] = {1000, 100, 10, 1};

    int openLock(vector<string>& deadends, string target) {
        for(string& d : deadends)
            deadend[stoi(d)] = true;

        int t = stoi(target);
        int depth = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int node = q.front(); q.pop();
                if(deadend[node]) continue; 
                if(node == t) return depth;
                for(int i=0; i<4; i++) {
                    for(int j=0; j<2; j++) {
                        int nextNode = rotate(node, i, j);
                        if(visit[nextNode]) continue;
                        visit[nextNode] = true;
                        q.push(nextNode);
                    }
                }
            }
            depth++;
        }

        return -1;
    }

    int rotate(int lock, int wheelIdx, bool up) {
        int wheelVal = lock / r[wheelIdx] % 10;
        int nextWheelVal = up ? (wheelVal + 1) % 10 : (wheelVal + 9) % 10;
        return lock / (r[wheelIdx] * 10) * (r[wheelIdx] * 10) + nextWheelVal * r[wheelIdx] + lock % r[wheelIdx];
    }
};

