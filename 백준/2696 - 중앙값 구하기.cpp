#include <iostream>
#include <queue>
using namespace std;
int main() {
    int t, m, a;
    vector<int> mid;
    scanf("%d", &t);
    while (t--) {
        mid.clear();
        priority_queue<int> max_pq;
        priority_queue<int, vector<int>, greater<int>> min_pq;
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &a);
            if (max_pq.size() > min_pq.size()) min_pq.push(a);
            else max_pq.push(a);
            if (!max_pq.empty() && !min_pq.empty() && max_pq.top() > min_pq.top()) {
                int t1 = max_pq.top();
                int t2 = min_pq.top();
                max_pq.pop();
                min_pq.pop();
                max_pq.push(t2);
                min_pq.push(t1);
            }
            if (i % 2 == 0) mid.push_back(max_pq.top());
        }
        printf("%d", mid.size());
        for (int i = 0; i < mid.size(); i++) {
            if (i % 10 == 0) printf("\n");
            printf("%d ", mid[i]);
        }
        printf("\n");
    }
}

/*
최대힙과 최소힙을 이용하여 중앙값을 구해줄 수 있었습니다.

최대힙의 크기를 최소힙보다 같거나 1 크도록 유지합니다.

최대힙은 항상 현재 입력받은 값보다 작은 값들, 최소힙은 항상 현재 입력받은 값보다 큰 값들로 유지해줍니다.

최대힙의 top이 최소힙의 top보다 크다면, 위 조건이 맞도록 스왑해줍니다.

최대힙의 top은 항상 중앙값을 유지합니다.
*/