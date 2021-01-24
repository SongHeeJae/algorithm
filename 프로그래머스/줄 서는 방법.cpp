#include <string>
#include <vector>
using namespace std;

long long factorial(int n) {
    long long res = 1;
    for(int i=2; i<=n; i++) res *= i;
    return res;
}

int getNumByIdx(vector<bool>& visit, int idx, int n) {
    for(int i=1; i<= n; i++)
        if(!visit[i] && idx-- == 0) {
            visit[i] = true;
            return i;
        }
    return -1;
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<bool> visit(n + 1, false);
    long long fact = factorial(n);
    for(int i=0; i<n; i++) {
        long long val = fact / (n - i);
        int idx = (k-1) / val;
        k -= val * idx;
        fact /= n - i;
        answer.push_back(getNumByIdx(visit, idx, n));
    }
    return answer;
}

/*
n = 4이고 k = 8이라면,
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2
2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
2 4 1 3
2 4 3 1
...
와 같은 수열에서 정답은 [2 1 4 3]이 될 것입니다.

4개의 수로 만들 수 있는 경우의 수는 4! = 24입니다.
첫째 자리의 수는 각각의 수가 24/4 = 6개씩 자리를 차지하고 있습니다.
k = 8이므로 8번째 수는, 1~n까지의 수 중에서 (8-1)/6 = 1번째 수(0에서 시작) 입니다.
1~n까지의 수 중에서 1번째 수는 2입니다. (방문했던 수를 제외한 1번째 수입니다.)
answer.pusk_back(2);
visit[2] = true;
k -= (6 * 1); // 6개씩 자리를 차지하고 있는 수에서 1번째(0부터 시작) 수를 구했으므로, 그 앞 단의 경우의 수(제일 앞 자리가 1번째보다 미만인 수)는 제외

이제 남은 수는 3개이므로, 3개의 수로 만들 수 있는 경우의 수는 3! = 6입니다.
둘째 자리의 수는 각각의 수가 6/3 = 2개씩 자리를 차지하고 있습니다.
k = 2이므로 2번째 수는, 1~n까지의 수 중에서 (2-1)/2 = 0번째 수(0에서 시작) 입니다.
1~n까지의 수 중에서 0번째 수는 1입니다. (방문했던 수를 제외한 0번째 수입니다.)
answer.push_back(1);
visit[1] = true;
k -= (2 * 0); // 2개씩 자리를 차지하고 있는 수에서 0번째(0부터 시작) 수를 구했으므로, 그 앞 단의 경우의 수(제일 앞 자리가 0번째보다 미만인 수)는 제외

... 반복
*/