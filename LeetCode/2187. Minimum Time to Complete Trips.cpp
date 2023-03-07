/*
이진 탐색을 이용하여 풀 수 있었습니다.
가능한 시간의 범위를 좁혀가면서 최소 시간을 구해줍니다.
*/

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1, r = 100000000000000;
        long long res = r;
        while(l <= r) {
            long long m = (l + r) / 2;
            if(isCompletable(time, totalTrips, m)) {
                r = m - 1;
                res = m;
            } else {
                l = m + 1;
            }
        }
        return res;
    }

    bool isCompletable(vector<int>& time, long long totalTrips, long long t) {
        for(int tm : time) {
            totalTrips -= t / tm;
            if(totalTrips <= 0) {
                return true;
            }
        }
        return false;
    }
};
