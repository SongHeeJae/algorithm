/*
각 인덱스의 nums1와 nums2를 쌍으로 묶어서, nums2 내림차순으로 정렬해줍니다.
정렬된 배열을 순차적으로 탐색하면, k개를 가지는 subsequence에 대해 현재까지 탐색된 nums2의 최솟값을 확인할 수 있습니다.
nums2와 매핑되는 nums1를, 최소힙을 이용하여 현재까지 탐색된 값 중에서 가장 큰 k개를 유지해주고, i번째 쌍을 선택했을 때 값이 최대가 되는지 확인해줍니다.
*/

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> p;
        for(int i=0; i<nums1.size(); i++) {
            p.push_back({nums2[i], nums1[i]});
        }

        sort(p.begin(), p.end(), greater<>());
        
        priority_queue<int> pq;
        long long s = 0;
        for(int i=0; i<k-1; i++) {
            pq.push(-p[i].second);
            s += p[i].second;
        }

        long long res = 0;
        for(int i=k-1; i<p.size(); i++) {
            s += p[i].second;
            res = max(res, s * p[i].first);

            pq.push(-p[i].second);
            s -= -pq.top();
            pq.pop();
        }
        return res;
    }
};
