/*
O(n logn)이라는 제약이 있었습니다.
map을 이용하여 각 원소의 개수를 세는데 O(n logn),
원소의 개수들을 정렬하는데 O(n logn)의 시간이 걸리게 됩니다.
*/

class Solution {
public:
    map<int, int> m;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for(int num : nums) m[num]++;
        
        vector<pair<int, int>> temp;
        for(pair<int, int> pi : m)
            temp.push_back({-pi.second, pi.first});
        sort(temp.begin(), temp.end());
        
        vector<int> res;
        for(int i=0; i<k; i++)
            res.push_back(temp[i].second);
        return res;
    }
};


/*
다음과 같이 개선할 수도 있었습니다.
map 대신 unordred_map 을 이용하여 각 원소의 개수를 세는데 O(n).
원소의 개수들을 정렬하는 대신, 힙을 이용하여 k개의 원소만 유지하여 O(n logk).
다만, res를 만드는데 O(k)가 필요하던 이전과는 달리 O(k logk)가 필요하게 됩니다.
또한, nums.size() == k라면,
k는 배열에서 유니크한 숫자 개수 이하이므로 각 요소들은 1번씩만 나왔다는 것을 의미하고,
정답은 어떤 순서든 상관없기 때문에, 그대로 nums를 반환해주면 됩니다.
*/
class Solution {
public:
    unordered_map<int, int> m;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size() == k) return nums;
        
        for(int num : nums) m[num]++;
        
        priority_queue<pair<int, int>> pq;
        for(pair<int, int> pi : m) {
            pq.push({-pi.second, pi.first});
            if(pq.size() > k) pq.pop();
        }
        
        vector<int> res;
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};