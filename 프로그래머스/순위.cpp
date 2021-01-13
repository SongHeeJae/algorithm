#include <string>
#include <vector>
#include <queue>

using namespace std;

int dfs(vector<vector<int>>& graph, int node, vector<bool>& visit) {
    int cnt = 1;
    visit[node] = true;
    for(int i=0; i<graph[node].size(); i++) {
        if(!visit[graph[node][i]]) {
            cnt += dfs(graph, graph[node][i], visit);
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> graph1(n+1), graph2(n+1);
    vector<bool> visit1, visit2;
    for(int i=0; i<results.size(); i++) {
        graph1[results[i][0]].push_back(results[i][1]);
        graph2[results[i][1]].push_back(results[i][0]);
    }
    for(int i=1; i<=n; i++) {
        visit1.clear(); visit2.clear();
        visit1.resize(n+1, false);
        visit2.resize(n+1, false);
        if(dfs(graph1, i, visit1) + dfs(graph2, i, visit2) == n + 1)
            answer++;
    }
    return answer;
}