#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;
int t, n, d, c, a, b, s;
vector<vector<pair<int, int>>> graph;
vector<int> dist;
void dijkstra(int start){
    int cnt = 0, t = 0;
    dist.clear();
    dist.resize(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int cost = pq.top().first;
        int vertex = pq.top().second;
        pq.pop();
        if (dist[vertex] < cost) continue;
        t = cost; // 마지막 컴퓨터 감염 시간
        for (int i = 0; i < graph[vertex].size(); i++) {
            int nextVertex = graph[vertex][i].first;
            int nextCost = cost + graph[vertex][i].second;
            if (dist[nextVertex] > nextCost) {
                dist[nextVertex] = nextCost;
                pq.push({ nextCost, nextVertex });
            }
        }
        cnt++;
    }
    printf("%d %d\n", cnt, t);
}

int main() {
    scanf("%d", &t);
    while (t--) {
        graph.clear();
        graph.resize(10001);
        scanf("%d %d %d", &n, &d, &c);
        for (int i = 0; i < d; i++) {
            scanf("%d %d %d", &a, &b, &s);
            graph[b].push_back({ a, s });
        }
        dijkstra(c);
    }
}