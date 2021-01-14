#include <string>
#include <vector>

using namespace std;

int map[100][100] = {0}; // map[i][j]는 (i, j)를 갈 수 있는 경로의 개수

void initPuddles(vector<vector<int>> &puddles) {
    for(int i=0; i<puddles.size(); i++) {
        map[puddles[i][1]-1][puddles[i][0]-1] = -1;
    }
}

void initMap(int n, int m) {
    for(int i=0; i<n; i++) {
        if(map[i][0] == -1) break;
        map[i][0] = 1;
    }
    for(int i=0; i<m; i++) {
        if(map[0][i] == -1) break;
        map[0][i] = 1;
    }
}

int solution(int m, int n, vector<vector<int>> puddles) {
    initPuddles(puddles);
    initMap(n, m);
    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            if(map[i][j] == -1) continue;
            if(map[i-1][j] != -1) map[i][j] += map[i-1][j];
            if(map[i][j-1] != -1) map[i][j] += map[i][j-1];
            map[i][j] %= 1000000007;
        }
    }
    return map[n-1][m-1];
}

/*
map[i][j] = map[i-1][j] + map[i][j-1] 입니다.

이 수식에서 물에 잠긴 지역만 별도로 처리해주면 되었습니다.
*/