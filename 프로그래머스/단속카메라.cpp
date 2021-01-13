#include <string>
#include <vector>
#include <queue>

using namespace std;

class compare {
public:
    bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
        if(a.first == b.first) {
            return a.second.first > b.second.first;
        } else {
            return a.first > b.first;
        }
    }  
};

int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<bool> visit(routes.size(), false);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare> pq;
    for(int i=0; i<routes.size(); i++) {
        pq.push({routes[i][0], {0, i}}); // 진입
        pq.push({routes[i][1], {1, i}}); // 진출
    }
    vector<int> enter;
    while(!pq.empty()) {
        int first = pq.top().first;
        int second = pq.top().second.first;
        int num = pq.top().second.second;
        pq.pop();
        if(second == 0) { // 진입
            enter.push_back(num);
        } else { // 진출
            if(!visit[num]) {
                for(int i=0; i<enter.size(); i++) {
                    visit[enter[i]] = true;
                }
                enter.clear();
                answer++;
            }
        }
    }    
    
    return answer;
}