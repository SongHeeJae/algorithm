#include <iostream>
#include <algorithm>
#include <vector>
#define INF 2147483647
using namespace std;

int n, a, b, ans = 0, cnt = 0, start = INF;
vector<pair<int, int>> arr;

bool comp(pair<int, int>& p1, pair<int, int>& p2) {
    if (p1.first == p2.first) return p1.second > p2.second;
    else return p1.first < p2.first;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        arr.push_back({ a, 1 });
        arr.push_back({ b, -1 });
    }
    sort(arr.begin(), arr.end(), comp);
    for (int i = 0; i < arr.size(); i++) {
        cnt += arr[i].second;
        if (cnt == 0) {
            ans += arr[i].first - start;
            start = INF;
        }
        else {
            if (start == INF) start = arr[i].first;
        }
    }
    printf("%d", ans);
}

/*
선분의 시작과 끝에 가중치를 부여해서 분할한 뒤, 정렬해줍니다.
선분의 시작점을 기억해놓고, 겹치는 선분은 다 무시하고 끝점에서 빠져나올 때, 그 길이를 더해줍니다.

​

https://blog.naver.com/gmlwo308/222388022586
위와 동일한 풀이로도 가능합니다.

#include <iostream>
#include <algorithm>
#include <vector>
#define INF 2147483647
using namespace std;

int n, a, b, ans = 0, pa = -INF, pb = -INF;
vector<pair<int, int>> arr;

bool comp(pair<int, int>& p1, pair<int, int>& p2) {
    if (p1.first == p2.first) return p1.second < p2.second;
    else return p1.first < p2.first;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        arr.push_back({ a, b });
    }
    sort(arr.begin(), arr.end(), comp);
    for (int i = 0; i < n; i++) {
        int a = arr[i].first;
        int b = arr[i].second;
        if (a < pb) {
            a = pb;
            if (a > b) b = a;
        }
        ans += b - a;
        pa = a, pb = b;
    }
    printf("%d", ans);
}
*/