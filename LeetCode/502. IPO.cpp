/*
주어진 profits와 capital 쌍을, capital 오름차순으로 정렬하여 project 목록을 구해줍니다.
정렬된 project를 순차적으로 탐색하며, 현 프로젝트를 지금 가지고 있는 w로 완료할 수 있는지 확인해줍니다.
완료할 수 있다면 우선순위 큐에 현 프로젝트의 profit을 넣어주고,
완료할 수 없다면 우선순위 큐에 담긴 가장 큰 profit을, 현 프로젝트를 완료할 수 있을 때까지 꺼내줍니다.
꺼내진 profit 들을 w를 증가시켜주면, 지금 시점에서 가장 큰 profit을 가진 프로젝트들을 처리한 셈입니다.
*/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> arr;
        for(int i=0; i<profits.size(); i++) {
            arr.push_back({capital[i], profits[i]});
        }

        sort(arr.begin(), arr.end());

        priority_queue<int> pq;
        for(int i=0; i<arr.size() && k; i++) {
            while (w < arr[i].first) {
                if(pq.empty()) return w;
                w += pq.top();
                pq.pop();
                k--;      
            }

            pq.push(arr[i].second);
         }

         while(!pq.empty() && k--) {
            w += pq.top();
            pq.pop();
         }

        return w;
    }
};
