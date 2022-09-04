/*
DFS를 이용하여 풀었습니다.
일의 자리 숫자와 k만큼 차이나는 수를 계속 덧붙여줍니다.
*/

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> result;
        for(int i=1; i<10; i++)
            dfs(result, n, k, i, 1);
        return result;
    }
    
    void dfs(vector<int>& result, int n, int k, int num, int depth) {
        if(depth == n) {
            result.push_back(num);
            return;
        }
        
        int val = num % 10;
        int pVal = val + k;
        int mVal = val - k;
        if(pVal == mVal) dfs(result, n, k, num * 10 + pVal, depth + 1);
        else {
            if(pVal < 10) dfs(result, n, k, num * 10 + pVal, depth + 1);
            if(mVal >= 0) dfs(result, n, k, num * 10 + mVal, depth + 1);
        }
    }
};
