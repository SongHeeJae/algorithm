#include <iostream>
#include <vector>
#include <queue>
#define INF 2147483647
#define W 1000000
using namespace std;

int n, m, c[1000], e;
vector<pair<int, int>> graph[1000];

int dijkstra() {
    priority_queue<pair<int, int>> pq;
    vector<int> dist(1000, INF);
    dist[0] = 0;
    pq.push({ 0, 0 });
    while (!pq.empty()) {
        int node = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (dist[node] < cost) continue;
        for (int i = 0; i < graph[node].size(); i++) {
            int nextNode = graph[node][i].first;
            int nextCost = cost + graph[node][i].second;
            if (nextCost < dist[nextNode]) {
                dist[nextNode] = nextCost;
                pq.push({ -nextCost, nextNode });
            }
        }
    }
    return dist[m];
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &e);
            if (e == 0) continue;
            graph[i].push_back({ j, e + (c[i] != c[j] ? W : 0) });
        }
    }
    int res = dijkstra();
    printf("%d %d", res / W, res % W);
}

/*
환승 횟수가 최소인 경로 중에서 소요 시간이 가장 짧은 경로를 찾아야합니다.
환승을 하는 경우, 소요 시간에 나올 수 있는 최대 시간보다 큰 값의 가중치를 더해줍니다.
다익스트라를 수행한 뒤, 가중치로 나눈 값이 환승 횟수, 가중치로 나눈 나머지가 소요 시간입니다. 
*/