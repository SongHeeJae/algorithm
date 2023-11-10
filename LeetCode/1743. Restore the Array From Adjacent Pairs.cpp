/*
n개의 요소를 가지는 배열에 대해 n - 1개의 인접한 쌍이 주어집니다.
주어진 쌍으로 양방향 그래프를 만들어주면, 배열의 시작과 끝 지점은 1개의 인접한 경로를 가지게 됩니다.
시작 지점에서부터 끝 지점에 도달하는 경로의 모든 값을 찾아주면 됩니다.
*/

class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        for(vector<int>& p : adjacentPairs) {
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
        }

        int s = INT_MIN, e = INT_MIN;
        for(auto& it : graph) {
            if(it.second.size() == 1) {
                if(s == INT_MIN) s = it.first;
                else e = it.first;
            }
        }

        vector<int> res;
        res.push_back(s);
        for(int v = graph[s].front(); v != e;) {
            res.push_back(v);
            v = res[res.size() - 2] == graph[v][0] ? graph[v][1] : graph[v][0];
        }
        res.push_back(e);

        return res;
    }
};
