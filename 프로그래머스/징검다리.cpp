#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int l = 1, r = distance;
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance); // 도착지점과의 거리도 구하기 위함
    while(l <= r) {
        int mid = (l+r)/2; // 거리의 최솟값
        int prev = 0;
        int cnt = 0; // 제거하는 바위의 갯수
        for(int rock : rocks) {
            if(rock - prev <= mid) cnt++; // 제거
            else prev = rock;
        }
        if(cnt <= n) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}