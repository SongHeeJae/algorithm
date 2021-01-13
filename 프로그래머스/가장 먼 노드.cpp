#include <string>
#include <vector>
#include <queue>
using namespace std;

int bfs(vector<vector<int>>& graph) {
    vector<bool> visit(graph.size(), false);
    int cnt = 0, p = -1;
    visit[1] = true;
    queue<pair<int, int>> q;
    q.push({1, 0});
    while(!q.empty()) {
        int node = q.front().first;
        int depth = q.front().second;
        q.pop();
        if(p != depth) cnt = 0;
        for(int i=0; i<graph[node].size(); i++) {
            if(!visit[graph[node][i]]) {
                visit[graph[node][i]] = true;
                q.push({graph[node][i], depth + 1});
            }
        }
        p = depth;
        cnt++;
    }
    return cnt;
}

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> graph(n+1);
    for(int i=0; i<edge.size(); i++) {
        int a = edge[i][0], b = edge[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    return bfs(graph);
}