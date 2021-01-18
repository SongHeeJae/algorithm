#include <string>
#include <vector>
using namespace std;

bool isPossible(vector<int> stones, int num, int k) {
    int dist = 0, cur = 0;
    for(int i=0; i<stones.size(); i++) {
        if(stones[i] - num <= 0) cur++;
        else {
            if(dist < cur) dist = cur;
            cur = 0;
        }
    }
    return dist < k;
}

int solution(vector<int> stones, int k) {
    int l = 0;
    int r = 200000000;
    stones.push_back(r);
    while(l<=r) {
        int mid = (l+r)/2;
        if(isPossible(stones, mid, k)) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

/*
각 원소 값의 범위를 보고 이분탐색을 이용한 문제라는걸 알았습니다.

mid를 건널 수 있는 사람의 수로 보았습니다.

건널 수 있다면 왼쪽 범위를 좁혀주고, 건널 수 없다면 오른쪽 범위를 좁혀주었습니다.

stones에 r을 하나 넣은 이유는, (3 4 0 0 0)의 형태인 경우 마지막에 0으로 끝날 때의 거리 재기가 누락되기 때문에 최댓값을 넣어주었습니다.
*/