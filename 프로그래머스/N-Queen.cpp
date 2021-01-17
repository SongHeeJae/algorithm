#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int map[12] = {0};

bool isPossible(int idx, int n) {
    for(int i=0; i<idx; i++)
        if(map[i] == map[idx] || map[i] - i == map[idx] - idx || idx - i == map[i] - map[idx]) return false;
    return true;
}

int nqueen(int idx, int n) { // idx 행번호
    if(idx == n)return 1;
    int cnt = 0;
    for(int i=0; i<n; i++) {
        map[idx] = i;
        if(isPossible(idx, n))
            cnt += nqueen(idx + 1, n);
    }
    return cnt;
}

int solution(int n) {
    return nqueen(0, n);
}

/*
같은 열 또는 같은 대각선이면 가지치기를 해주며 모든 경우의 수를 구해주었습니다.
*/