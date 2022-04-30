/*
크루스칼 알고리즘을 이용하여 풀면 됩니다.
*/

class Solution {
public:
    vector<pair<int, pair<int, int>>> edges;
    int p[1001] = {0};
        
    int minCostConnectPoints(vector<vector<int>>& points) {
        for(int i=0; i<points.size(); i++) {
            for(int j=1; j<points.size(); j++) {
                edges.push_back({abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), {i, j}});
            }
        }
        
        sort(edges.begin(), edges.end());
        
        int cnt = 0;
        int cost = 0;
        for(auto edge : edges) {
            int a = edge.second.first;
            int b = edge.second.second;
            int c = edge.first;
            int pa = findParent(a);
            int pb = findParent(b);
            if(pa != pb) {
                p[pa] = pb;
                cost += c;
                if(++cnt == points.size() - 1) break;
            }
        }
        return cost;
    }
    
    int findParent(int x) {
        if(p[x] == 0) return x;
        return p[x] = findParent(p[x]);
    }
};