/*
각 값을 루트로 하는 모든 서브 트리의 수를 구해주고, 구해진 결과는 재사용해줍니다.
arr을 오름차순 정렬하면, 루트보다 작은 값에 대해서만 곱을 테스트해볼 수 있습니다.
*/

class Solution {
public:
    unordered_map<int, int> arrMap;
    int dp[1000] = {0};

    const int MOD = 1e9 + 7;

    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size(); i++) arrMap[arr[i]] = i;

        int cnt = 0;
        for(int i=0; i<arr.size(); i++) {
            cnt += numFactoredBinaryTrees(arr, i);
            cnt %= MOD;
        }
        return cnt;
    }

    int numFactoredBinaryTrees(vector<int>& arr, int idx) {
        if(dp[idx]) return dp[idx];

        dp[idx] = 1;
        for(int i=0; i<idx; i++) {
            if(arr[idx] % arr[i]) continue;
    
            auto f = arrMap.find(arr[idx] / arr[i]);
            if(f == arrMap.end()) continue;
            
            dp[idx] += (long long)numFactoredBinaryTrees(arr, i) * numFactoredBinaryTrees(arr, f->second) % MOD;
            dp[idx] %= MOD;
            
        }

        return dp[idx];
    }
};
