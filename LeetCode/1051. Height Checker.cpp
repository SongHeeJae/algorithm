/*
카운트 정렬을 통해 O(n)에 풀 수 있었습니다.
*/

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int cnt[101] = {0};
        for(int h : heights) cnt[h]++;
        int res = 0, idx = 0;
        for(int i=1; i<=100; i++) {
            while(cnt[i]--) {
                if(heights[idx++] != i) res++;
            }
        }
        return res;
    }
};

