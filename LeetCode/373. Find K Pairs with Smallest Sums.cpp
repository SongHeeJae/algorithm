/*
min heap은 k개의 pair를, top에는 smallest sum을 가지는 pair를 유지해줄 것입니다.
nums1에서 가장 작은 k개의 값과 nums2[0]의 pair를 min heap에 넣어줍니다.
min heap에 저장된 top을 꺼내주고, nums2의 다음으로 작은 값과의 pair를 min heap에 삽입해줍니다.
nums1와 nums2는 오름차순으로 정렬되어있기 때문에, 가장 작은 값과의 pair를 min heap에 넣어주면, 결과를 구해낼 수 있습니다.
*/

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();

        priority_queue<pair<int, pair<int, int>>> pq;
        for(int i=0; i<k && i<n; i++) {
            pq.push({-nums1[i]-nums2[0], {i, 0}});
        }

        vector<vector<int>> res;
        while(k-- && !pq.empty()) {
            pair<int, pair<int, int>> p = pq.top();
            pq.pop();

            int idx1 = p.second.first;
            int idx2 = p.second.second;
            res.push_back({nums1[idx1], nums2[idx2]});
            
            if(idx2+1 < m) 
                pq.push({-nums1[idx1]-nums2[idx2+1], {idx1, idx2+1}});
        }
       
        return res;
    }
};
