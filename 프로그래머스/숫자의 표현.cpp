#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int cnt = 0;
    for(int i=1; i<=n; i++) {
        int sum = 0;
        for(int j=i; sum < n; j++) sum += j;
        if(sum == n) cnt++;
    }
    return cnt;
}

/*
1~n인 각 수에서 시작했을 때, 연속된 합이 n이 나올 수 있는지 구해주었습니다.
*/