/*
BFS 문제였습니다.
주어진 arr을 이용하여, 각 arr의 값에서 이동할 수 있는 index 번호를 그래프로 만들어줍니다.
0에서부터 마지막 인덱스에 도달할 때 까지 BFS를 수행해줍니다.
[7, 7, 7, 7, 7, ...] 같은 케이스의 경우 그래프에서 이미 방문했던 index들을 계속 재탐색하며 시간 초과가 뜰 수 있는데,
이미 방문한 index에 대해 재탐색을 수행할 필요 없도록, 그래프에서 이미 방문했던 index들은 제거해주었습니다.
*/

class Solution {
public:
    map<int, vector<int>> grp;
    bool v[50000] = { false };
    queue<int> q;

    int minJumps(vector<int>& arr) {
        for(int i=0; i<arr.size(); i++)
            grp[arr[i]].push_back(i);

        q.push(0);
        v[0] = true;

        int cnt = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int x = q.front();
                q.pop();

                if(x == arr.size() - 1) return cnt;

                if(x < arr.size() - 1) pushIfVisitable(x + 1);
                if(x > 0) pushIfVisitable(x - 1);
                for(int nxt : grp[arr[x]]) pushIfVisitable(nxt);

                grp[arr[x]].clear();
            }
            cnt++;
        }

        return -1;
    }
    
    void pushIfVisitable(int idx) {
        if(v[idx]) return;
        q.push(idx);
        v[idx] = true;
    }
};
