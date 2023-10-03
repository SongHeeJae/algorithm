/*
각 수가 n개 나오면, (n*(n-1))/2개의 쌍을 만들 수 있습니다.
nums를 탐색하며 수의 개수를 세주고, 모든 쌍의 개수를 구해줍니다.
*/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int c[101] = {0};
        int res = 0;
        for(int n : nums) {
            res += c[n]++;
        }
        return res;
    }
};
