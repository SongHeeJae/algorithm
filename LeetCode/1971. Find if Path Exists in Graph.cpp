/*
union find를 이용하여 풀었습니다.
주어진 간선들을 이용하여 노드를 그룹화해주고, source와 destination이 같은 그룹인지 확인해줍니다.
*/

class Solution {
public:
    int p[200000];
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for(int i=0; i<n; i++) p[i] = i;
        for(auto& e : edges) p[find(e[0])] = find(e[1]);
        return find(source) == find(destination);
    }

    int find(int x) {
        if(p[x] == x) return x;
        return p[x] = find(p[x]);
    }
};

