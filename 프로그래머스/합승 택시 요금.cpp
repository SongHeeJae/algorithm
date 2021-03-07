#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 666666666
using namespace std;

vector<vector<pair<int, int>>> graph(201, vector<pair<int, int>>());

vector<int> dijkstra(int n, int start) {
    priority_queue<pair<int, int>> pq;
    vector<int> fare(n+1, INF);
    fare[start] = 0;
    pq.push({0, start});
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int pos = pq.top().second;
        pq.pop();
        if(cost > fare[pos]) continue;
        for(int i=0; i<graph[pos].size(); i++) {
            int nextPos = graph[pos][i].first;
            int nextCost = cost + graph[pos][i].second;
            if(fare[nextPos] > nextCost) {
                fare[nextPos] = nextCost;
                pq.push({-nextCost, nextPos});
            }
        }
    }
    return fare;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int ans = INF;
    for(int i=0; i<fares.size(); i++) {
        int a = fares[i][0];
        int b = fares[i][1];
        int f = fares[i][2];
        graph[a].push_back({b, f});
        graph[b].push_back({a, f});
    }
    
    vector<int> sFare = dijkstra(n, s);
    vector<int> aFare = dijkstra(n, a);
    vector<int> bFare = dijkstra(n, b);
    for(int i=1; i<= n; i++)
        ans = min(ans, sFare[i] + aFare[i] + bFare[i]);
    return ans;
}