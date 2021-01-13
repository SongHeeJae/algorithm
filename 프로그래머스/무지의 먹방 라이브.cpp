#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int solution(vector<int> food_times, long long k) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    long long int kk = k;
    for(int i=0; i<food_times.size(); i++) {
        kk -= food_times[i];
        pq.push({food_times[i], i});
    }
    if(kk>=0) return -1;
    kk = 0;
    long long int time;
    while((time = (pq.top().first - kk) * pq.size()) <= k) {
        k -= time;
        kk = pq.top().first;
        pq.pop();
    }
    vector<pair<int, int>> temp;
    while(!pq.empty()) {
        temp.push_back({pq.top().second, pq.top().first});
        pq.pop();
    }
    sort(temp.begin(), temp.end());
    return temp[k % temp.size()].first + 1;
}