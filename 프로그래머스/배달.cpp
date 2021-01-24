#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    priority_queue<pair<int, int>> pq;
    vector<int> minDist(N + 1, INF);
    minDist[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()) {
        int time = -pq.top().first;
        int town = pq.top().second;
        pq.pop();
        if(minDist[town] < time) continue;
        if(time <= K) answer++;
        for(int i=0; i<road.size(); i++) {
            int nextTown;
            if(road[i][0] == town) nextTown = road[i][1];
            else if(road[i][1] == town) nextTown = road[i][0];
            else continue;
            int nextTime = time + road[i][2];
            if(nextTime < minDist[nextTown]) {
                minDist[nextTown] = nextTime;
                pq.push({-nextTime, nextTown});
            }
        }
    }
    return answer;
}

/*
다익스트라로 방문하는 정점의 시간이 K 이하이면 answer++ 해주었습니다.
*/