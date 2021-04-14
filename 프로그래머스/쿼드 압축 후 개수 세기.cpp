#include <string>
#include <vector>

using namespace std;

int res1 = 0, res2 = 0;

void run(vector<vector<int>>& arr, int x, int y, int len) {
    if(len == 0) return;
    bool one = true, zero = true;
    for(int i=x; i<x + len; i++) {
        for(int j= y; j< y + len; j++) {
            if(arr[i][j]) one = false;
            if(!arr[i][j]) zero = false;
        }
    }
    if(one) {
        res1++;
        return;
    }
    if(zero) {
        res2++;
        return;
    }
    run(arr, x, y, len/2);
    run(arr, x, y + len/2, len/2);
    run(arr, x + len/2, y, len/2);
    run(arr, x + len/2, y + len/2, len/2);
}

vector<int> solution(vector<vector<int>> arr) {
    run(arr, 0, 0, arr.size());
    return {res1, res2};
}

/*
재귀적으로 범위를 네 개로 분할해준 뒤, 분할된 범위의 숫자가 모두 동일하다면 해당 숫자의 갯수를 1 더해주었습니다.
*/