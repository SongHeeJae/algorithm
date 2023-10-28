/*
1 <= n <= 10^9이므로, n의 30비트를 검사하여 powers를 미리 생성해줍니다.
query를 확인하며 범위 내에 곱을 구해줍니다.
*/

class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        for(int i=0; i<31; i++) {
            if((n >> i) & 1) {
                powers.push_back(1 << i);
            }
        }

        vector<int> res;

        for(auto& q : queries) {
            long long val = 1;
            for(int i=q[0]; i<=q[1]; i++)
                val = val * powers[i] % MOD;
            res.push_back(val);
        }

        return res;
    }
};
