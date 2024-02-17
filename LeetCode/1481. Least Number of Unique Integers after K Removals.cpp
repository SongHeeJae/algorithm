/*
각 숫자가 나온 빈도 수를 구해줍니다.
빈도 수를 오름차순으로 정렬하고, 각 빈도 수 만큼 제거 연산을 수행하면, 고유한 숫자 1개를 제거하게 됩니다.
k가 음수가 될 때 까지 연산을 수행해줍니다.
*/

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> numToCntMap;
        for(int num : arr) numToCntMap[num]++;

        vector<int> cnt;
        for(auto it : numToCntMap) cnt.push_back(it.second);
        sort(cnt.begin(), cnt.end());
        for(int i=0; i<cnt.size(); i++) {
            k -= cnt[i];
            if(k < 0) return cnt.size() - i;
        }
        return 0;
    }
};
