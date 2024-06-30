/*
연결된 도시가 많을수록 높은 value를 주면 됩니다.
각 도시마다 연결된 도시 수를 구해주고, 오름차순 정렬해줍니다.
i번째 도시를 통해 얻을 수 있는 값의 합은, (연결된 도시의 개수) * (i + 1) 이 됩니다.
*/

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> cnt(n, 0);
        for(auto& r : roads) {
            cnt[r[0]]++;
            cnt[r[1]]++;
        }

        sort(cnt.begin(), cnt.end());

        long long res = 0;
        for(int i=0; i<n; i++) {
            res += (long long)cnt[i] * (i + 1);
        }
        return res;
    }
};
