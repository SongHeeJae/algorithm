#include <vector>
using namespace std;

int MOD = 20170805;

void initMap(int map[500][500][2], int m, int n, vector<vector<int>>& city_map) {
    for(int i=0; i<m && city_map[i][0] != 1; i++) map[i][0][1] = 1;
    for(int i=0; i<n && city_map[0][i] != 1; i++)map[0][i][0] = 1;
}

int solution(int m, int n, vector<vector<int>> city_map) {
    int map[500][500][2] = {0}; // 0 왼쪽에서 온 경우, 1 위쪽에서 온 경우
    initMap(map, m, n, city_map);
    for(int i=1; i<m; i++) {
        for(int j=1; j<n ;j++) {
            if(city_map[i][j] != 1) {
                map[i][j][0] = (map[i][j-1][0] + (city_map[i][j-1] != 2 ? map[i][j-1][1] : 0)) % MOD;
                map[i][j][1] = (map[i-1][j][1] + (city_map[i-1][j] != 2 ? map[i-1][j][0] : 0)) % MOD;
            }
        }
    } 
    return (map[m-1][n-1][0] + map[m-1][n-1][1]) % MOD;
}
/*

왼쪽에서 오는 경우와 위쪽에서 오는 경우를 구분하여 DP로 구현하였습니다.

city_map[i][j] == 0 또는 2라면,
- 왼쪽에서 오는 경우의 수 == (왼쪽 좌표에서 왼쪽으로 넘어왔던 경우의 수 + (왼쪽 좌표가 2가 아니라면, 왼쪽 좌표에서 위쪽으로 넘어왔던 경우의 수))
- 위쪽에서 오는 경우의 수 == (위쪽 좌표에서 위쪽으로 넘어왔던 경우의 수 + (위쪽 좌표가 2가 아니라면, 위쪽 좌표에서 왼쪽으로 넘어왔던 경우의 수))

map[i][j][0]은 (i, j) 에서 왼쪽으로 넘어온 경우의 수,
map[i][j][1]은 (i, j) 에서 위쪽으로 넘어온 경우의 수를 의미합니다.

*/