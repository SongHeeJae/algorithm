/*
BFS를 이용하여 풀 수 있었습니다.
각 버스 정류장을 경유하는 버스를 간선으로 만들어줍니다.
시작 지점에서 이동할 수 있는 버스들을 찾아주고, 해당 버스들에서 이동 가능한 버스 정류장들로 이동해줍니다.
도착 지점을 찾을 때까지 반복합니다.
*/

class Solution {
public:
    vector<int> graph[1000000];
    int visitBusStop[1000000] = {0};
    bool visitBus[500] = {false};

    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        for(int bus=0; bus<routes.size(); bus++) {
            for(int busStop : routes[bus]) {
                graph[busStop].push_back(bus);
            }
        }

        queue<int> q;
        q.push(source);
        visitBusStop[source] = 1;

        while(!q.empty()) {
            int curBusStop = q.front();
            q.pop();
            
            if(curBusStop == target) {
                return visitBusStop[curBusStop] - 1;
            }

            for(int bus : graph[curBusStop]) {
                if(visitBus[bus]) continue;
                visitBus[bus] = true;
                for(int busStop : routes[bus]) {
                    if(visitBusStop[busStop]) continue;
                    visitBusStop[busStop] = visitBusStop[curBusStop] + 1;
                    q.push(busStop);
                }
            }
        }
        return -1;
    }
};
