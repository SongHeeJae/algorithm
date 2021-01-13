#include <cstdio>
#define INF 987654321
int n, m, a[100000], c = 0, ans = INF;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        long long int s = 0;
        for (int j = i; j < n; j++) {
            s += a[j];
            if (s >= m) {
                if(ans > j - i) ans = j - i + 1;
                break;
            }
        }
    }
    printf("%d", ans != INF ? ans : 0);
}

/*
a[i]~a[j] 사이의 모든 구간 합에 대하여 구하지만, 현재 검사하고있는 i에 대한 구간합을 더 이상 확인할 필요가 없으면 break;를 해주고, 다음 i에 대하여 구간 합을 구해줬습니다. 
*/


/*

아래 코드는 다른 분들의 코드를 보다가 이런 방법으로도 풀 수 있다는 것을 알았습니다!
예제 입력을 통해서 쉽게 생각해보겠습니다.

10 15
5 1 3 5 10 7 4 9 2 8

입력받은 수를 하나씩 우측으로 이동해가며 합을 구해줍니다. 그러면서 queue에서 계속 push 해줍니다.

[5] 1 3 5 10 7 4 9 2 8 -> 합 : 5
[5 1] 3 5 10 7 4 9 2 8 -> 합 : 6
[5 1 3] 5 10 7 4 9 2 8 -> 합 : 9
[5 1 3 5] 10 7 4 9 2 8 -> 합 : 14
[5 1 3 5 10] 7 4 9 2 8 -> 합 : 24, 길이 : 5

그러다가 합이 입력 값 S(15)를 넘겼다면, [] 구간을 오른쪽으로 이동시켜줍니다.

5 [1 3 5 10] 7 4 9 2 8 -> 합 : 19, 길이 : 4
5 1 [3 5 10] 7 4 9 2 8 -> 합 : 18, 길이 : 3
5 1 3 [5 10] 7 4 9 2 8 -> 합 : 15, 길이 : 2
5 1 3 5 [10] 7 4 9 2 8 -> 합 : 10, S를 넘기지않으므로 다음 입력 받음. 

위와 같이 부분 합이 S 이상 일 때까지 queue에서 pop해주며 [] 구간을 오른쪽으로 이동시켜줬습니다
이제는 다시 다음 입력을 받고 동일한 과정을 진행하면 됩니다.
​
#include <iostream>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;
int n, m, a, ans = INF;
long long int s = 0;
queue<int> q;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        q.push(a);
        s += a;
        while (s >= m) {
            ans = min((int)q.size(), ans);
            s -= q.front();
            q.pop();
        }
    }
    printf("%d", ans != INF ? ans : 0);
}

*/
