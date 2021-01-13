#include <iostream>
using namespace std;

int n, h, a;
int top[500001] = { 0 };
int bot[500001] = { 0 };
int s_top[500002] = { 0 };
int s_bot[500002] = { 0 };
int main() {
    scanf("%d %d", &n, &h);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        (i % 2 ? top : bot)[a]++;
    }
    for (int i = h; i >= 1; i--) {
        s_top[i] = top[i] + s_top[i + 1];
        s_bot[i] = bot[i] + s_bot[i + 1];
    }
    int res = 987654321, res_cnt = 0;
    for (int i = 1; i <= h; i++) {
        int val = s_bot[i] + s_top[h-i+1];
        if (val == res) res_cnt++;
        else if (val < res) {
            res_cnt = 1;
            res = val;
        }
    }
    printf("%d %d", res, res_cnt);
}

