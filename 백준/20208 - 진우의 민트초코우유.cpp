#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m, h, a, sx, sy, ans = 0;
vector<pair<int, int>> milks;
bool visit[10] = { false };

void dfs(int x, int y, int mm, int depth) {
    if (mm >= abs(x - sx) + abs(y - sy)) {
        ans = max(depth, ans);
    }
    if (depth == milks.size()) return;
    for (int i = 0; i < milks.size(); i++) {
        if (visit[i]) continue;
        int dist = abs(x - milks[i].first) + abs(y - milks[i].second);
        if (dist > mm) continue;
        visit[i] = true;
        dfs(milks[i].first, milks[i].second, mm + h - dist, depth + 1);
        visit[i] = false;
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &h);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a);
            if (a == 1) sx = i, sy = j;
            else if (a == 2) milks.push_back({ i, j });
        }
    }
    dfs(sx, sy, m, 0);
    printf("%d", ans);
}

/*
우유의 위치를 기억해두고, 시작 위치에서 각 우유를 선택하며 이동해나갑니다.
우유를 선택할 때마다 해당 지점에서 집에 돌아갈 수 있는지 확인하고, 최대 개수를 업데이트해줍니다.
*/