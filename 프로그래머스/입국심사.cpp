#include <string>
#include <vector>
using namespace std;

int extractMaxTime(vector<int>& times) {
    int max = -1;
    for(int time : times) {
        if(max < time) max = time;
    }
    return max;
}

long long solution(int n, vector<int> times) {
    long long l = 1, r = (long long)extractMaxTime(times) * n;
    while(l <= r) {
        long long sum = 0;
        long long mid = (l + r) / 2; // 처리하는데 걸리는 시간
        for(int time : times) {
            sum += mid / time; // 각 심사관이 mid시간 안에 처리할 수 있는 사람 수
        }
        if(n <= sum) { // 처리 가능한 시간인 경우
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return l;
}