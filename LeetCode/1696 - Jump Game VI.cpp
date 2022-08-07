/*
우선순위 큐를 이용한 누적합으로 풀 수 있었습니다.

우선순위 큐에는 각 인덱스에 도달했을 때 얻을 수 있는 최대 점수를 저장해줍니다.

k의 범위를 벗어났는지 확인하기 위해 인덱스 번호도 함께 저장해줍니다.

우선순위 큐에는 범위 내에 속하는 값 중 최대 누적합 + 현재 인덱스의 점수를 지속적으로 저장하며, 최대 점수를 유지해줍니다.

배열의 마지막 인덱스에 도달해야하므로, 우선순위 큐에서 마지막에 도달했던 점수의 합을 반환해줍니다.
*/

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq; // {누적합, 인덱스}
        pq.push({nums[0], 0});
        for(int i=1; i<nums.size(); i++) {
            while(!pq.empty() && pq.top().second < i - k) pq.pop();
            pq.push({nums[i] + pq.top().first, i});
        }
        
        while(pq.top().second != nums.size() - 1) pq.pop();
        return pq.top().first;
    }
};
