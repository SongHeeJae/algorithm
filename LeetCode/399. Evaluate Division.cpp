/*
equations으로 간선에 가중치가 있는 그래프를 만들어줍니다.
a -> b (value)
b -> a (1 / value)
query를 수행하며 query[0] -> query[1]로 가는 경로를 찾아주고, 경로의 가중치를 모두 곱해줍니다.
*/

class Solution {
public:
    map<string, vector<pair<string, double>>> graph;
    set<string> visit;

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0; i<equations.size(); i++) {
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        }

        vector<double> res;
        for(int i=0; i<queries.size(); i++) {
            visit.clear();
            res.push_back((graph.find(queries[i][0]) == graph.end() && graph.find(queries[i][1]) == graph.end()) ? -1 : dfs(queries[i][0], queries[i][1]));
        }
        return res;
    }

    double dfs(string start, string end) {
        if(visit.find(start) != visit.end()) return -1;
        visit.insert(start);

        if(start == end) return 1;
        
        for(pair<string, double>& nxt : graph[start]) {
            double res = dfs(nxt.first, end);
            if(res != -1) return res * nxt.second;
        }

        return -1;
    }
};
