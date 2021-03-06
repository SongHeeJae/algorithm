#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> request(1001, vector<int>());
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int getNotEmptyIdx(int t) { // t 다음으로 비어있지 않은 인덱스
    for(int i=t+1; i<1001; i++) 
        if(request[i].size() != 0) return i;
    return -1;
}

void fillTask(int requestTime) {
    for(int i=0; i<request[requestTime].size(); i++)
        pq.push({request[requestTime][i], requestTime});
}

int solution(vector<vector<int>> jobs) {
    for(int i=0; i<jobs.size(); i++)
        request[jobs[i][0]].push_back(jobs[i][1]);

    int total = 0, startTime = getNotEmptyIdx(-1);
    
    for(int i=0; i<request[startTime].size(); i++)
        pq.push({request[startTime][i], startTime});

    while(!pq.empty()) {
        int time = pq.top().first;
        int rtime = pq.top().second;
        pq.pop();
        for(int i=startTime+1; i <1001 && i<=startTime+time; i++) // 현재 작업 마치는 시간까지 들어온 새로운 요청
            fillTask(i);
        
        startTime += time;
        total += startTime - rtime; 
        
        if(pq.empty()) { // 들어온 작업이 없다면 다음 작업 요청
            startTime = getNotEmptyIdx(startTime);
            if(startTime == -1) break;
            fillTask(startTime);
        }
    }
    return total / jobs.size();
}

/*
각 요청 시간에 따른 작업을 기록해놓고, 각 작업이 끝날 때마다 그 사이에 들어온 요청들을 우선순위 큐를 이용하여 최소 시간이 걸리는 작업 순으로 정렬해주었습니다.
만약 새로이 작업할 것이 없다면, 다음 요청을 받아냈습니다. 
*/