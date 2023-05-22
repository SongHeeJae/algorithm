/*
각 element에 대한 빈도 수를 구해주고, 빈도 수 별로 나타나는 element를 그룹화 해줍니다.
정답은 유니크한 것이 보장되므로, 가장 상위 빈도 수 부터 k개의 그룹을 찾아줍니다.
*/

class Solution {
public:
    unordered_map<int, int> numTofrequencyMap;
    unordered_map<int, vector<int>> frequencyToNumsMap;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int maxFrequency = 0;
        for(int n : nums) maxFrequency = max(maxFrequency, ++numTofrequencyMap[n]);
        for(auto& p : numTofrequencyMap)
            frequencyToNumsMap[p.second].push_back(p.first);

        vector<int> res;
        while(res.size() < k) {
            vector<int>& numsByMap = frequencyToNumsMap[maxFrequency--];
            if(!numsByMap.empty()) 
                for(int n : numsByMap) res.push_back(n);
        }
        return res;
    }
};
