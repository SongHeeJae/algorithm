#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int map[102][102][2][2] = {0}; // 3차원 0기둥1보, 4차원 0은 왼쪽보 아랫기둥 기준, 1은 오른쪽보 윗기둥 기준

bool comp(vector<int>& a, vector<int>& b) {
    if(a[0] == b[0]) {
        if(a[1] == b[1]) return a[2] < b[2];
        else return a[1] < b[1];
    }
    else return a[0] < b[0];
}

bool isPossible(int n) {
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            if(map[i][j][0][0] && map[i+1][j][0][1] ) { // 기둥
                if(i != 0 && !map[i][j][0][1] && !map[i][j][1][0] && !map[i][j][1][1] ) // 바닥이 아닌데, 아래에 받쳐주는 기둥이 없고, 받쳐주는 보도 없는 경우
                    return false;
            }
            if(map[i][j][1][0] && map[i][j+1][1][1]) { // 보
                if(!map[i][j][0][1] && !map[i][j+1][0][1] && (!map[i][j][1][1] || !map[i][j+1][1][0])) // 양 옆에 받쳐주는 기둥도 없고, 양 옆에 보가 2개 있지 않은 경우
                    return false;
            }
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    for(int i=0; i<build_frame.size(); i++) {
        int x, y, nx, ny;
        x = build_frame[i][1];
        y = build_frame[i][0];
        nx = x + !build_frame[i][2];
        ny = y + build_frame[i][2];
        map[x][y][build_frame[i][2]][0] = build_frame[i][3];
        map[nx][ny][build_frame[i][2]][1] = build_frame[i][3];
        if(!isPossible(n)) {
            map[x][y][build_frame[i][2]][0] = !build_frame[i][3];
            map[nx][ny][build_frame[i][2]][1] = !build_frame[i][3];
        }
    }
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            if(map[i][j][0][0] && map[i+1][j][0][1])
                answer.push_back({j, i, 0});
            if(map[i][j][1][0] && map[i][j+1][1][1])
                answer.push_back({j, i, 1});
        }
    }
    sort(answer.begin(), answer.end(), comp);
    return answer;
}

/*
각 좌표에는 윗 기둥, 아랫 기둥, 보의 오른쪽, 보의 왼쪽이 들어갈 수 있습니다.
작업 순서에 따라 일단 설치 또는 삭제를 진행하고, 작업을 진행하고 난 뒤의 기둥과 보의 규칙이 맞지 않는다면 해당 작업을 취소해주었습니다.
*/