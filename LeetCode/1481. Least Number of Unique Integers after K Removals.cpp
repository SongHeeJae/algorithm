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

/*
arr.length <= 10^5 이기 때문에, 각 빈도 수에 등장하는 고유한 숫자의 개수를, 상수 시간에 접근할 수 있도록 배열을 이용하여 초기화주면, 별도 정렬 없이 선형 시간에 결과를 구할 수 있습니다.  
*/

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> numToCntMap;
        for(int num : arr) numToCntMap[num]++;

        vector<int> cnt(arr.size() + 1, 0);
        for(auto it : numToCntMap) cnt[it.second]++;

        int c = 0;
        for(int i=1; i<cnt.size(); i++) {            
            while(cnt[i]--) {
                k -= i;
                c++;
                if(k < 0) return numToCntMap.size() - c + 1;
            }
        }
        return 0;
    }
};


