/*
equations를 이용하여 양방향 그래프를 만들어주고,
values를 이용하여 두 정점 간 비용을 기억해줍니다.
x / y = 1.5 라면, y / x = 1 / 1.5 이므로,
[{x, y} = 1.5, {y, x} = 1/1.5] 를 기억해주면 됩니다.

queries에 나타나는 두 정점 간 경로의 모든 정점을 구해줍니다.
전처리된 비용을 이용하여 경로 간에 나타나는 비용을 모두 곱해주면 됩니다.
*/

class Solution {
public:
    map<pair<string, string>, double> val;
    map<string, vector<string>> graph;
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0; i<values.size(); i++) {
            graph[equations[i][0]].push_back(equations[i][1]);
            graph[equations[i][1]].push_back(equations[i][0]);
            val.insert({{equations[i][0], equations[i][1]}, values[i]});
            val.insert({{equations[i][1], equations[i][0]}, 1/values[i]});
        }
        
        vector<double> result;
        vector<string> path;
        set<string> visit;
        for(vector<string>& query : queries) {
            auto f1 = graph.find(query[0]);
            auto f2 = graph.find(query[1]);
            if(f1 == graph.end() || f2 == graph.end()) {
                result.push_back(-1);
                continue;
            }
            
             if(query[0] == query[1]) {
                result.push_back(1);
                continue;
            }
            
            path.clear();
            visit.clear();
           
            result.push_back(dfs(query[0], query[1], path, visit));
        }
        
        return result;
    }
    
    double dfs(string& node, string& end, vector<string>& path, set<string>& visit) {
        path.push_back(node);
        
        if(node == end) {
            double res = 1;
            for(int i=1; i<path.size(); i++) {
                res *= val[{path[i-1], path[i]}];
            }
            return res;
        }
        
        visit.insert(node);
        for(auto& nxt : graph[node]) {
            if(visit.find(nxt) != visit.end()) continue;
            double ret = dfs(nxt, end, path, visit);
            if(ret != -1) return ret;
        }
        
        path.pop_back();
        return -1;
    }
};