/*
이진 탐색 문제였습니다.
days는 최대 50,000, weights[i]는 최대 500의 값을 가질 수 있으므로, capacity는 1~250,000의 범위를 가지게 됩니다.
이진 탐색으로 capacity의 범위를 좁혀나가면서, days 일 내에 모든 weights를 처리하는 capacity의 범위를 구할 수 있었습니다.
현재의 중간 값으로 처리할 수 있다면, 우측 범위를 좁혀주고, 그렇지 않다면, 좌측 범위를 좁혀줍니다.
처리 가능 여부는 weights를 순차 탐색하며 구할 수 있습니다.
순차적으로 weight를 처리하면서, 주어진 capacity로 더 이상 처리할 수 없다면, 다음 날로 미뤄줍니다.
*/

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 1, r = 25000000;
        int ans = INT_MAX;
        while(l <= r) {
            int m = (l + r) / 2;
            if(isOk(weights, days, m)) {
                r = m - 1;
                ans = m;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
private:
    bool isOk(vector<int>& weights, int days, int capacity) {
        int c = capacity;
        for(int w : weights) {
            if(c < w) {
                if(capacity < w || --days == 0) return false;
                c = capacity;
            }
            c -= w;    
        }
        return true;
    }
};
