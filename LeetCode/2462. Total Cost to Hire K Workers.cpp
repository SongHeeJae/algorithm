/*
2개의 min heap과 투포인터를 이용하여 풀 수 있었습니다.
각 세션의 후보자들을 나타내기 위해, 좌측과 우측 포인터에서 candidates 또는 남은 workers 수 만큼의 cost를 각 min heap에 유지해줍니다.
2개의 min heap에서 가장 작은 cost를 가지는 worker를 고용해주면 됩니다.
*/

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        int l = 0, r = costs.size() - 1;
        priority_queue<int> pq1, pq2;
        long long res = 0;
        while(k--) {
            while(pq1.size() < c && l <= r) pq1.push(-costs[l++]);
            while(pq2.size() < c && l <= r) pq2.push(-costs[r--]);
            int c1 = pq1.empty() ? INT_MAX : -pq1.top();
            int c2 = pq2.empty() ? INT_MAX : -pq2.top();
            if(c1 <= c2) res += c1, pq1.pop();
            else res += c2, pq2.pop();
        }
        return res;
    }
};
