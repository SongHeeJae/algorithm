#include <string>
using namespace std;
bool visit[11][11][11][11] = {false};
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int dir[26];
char d[] = "UDLR";
int solution(string dirs) {
    int answer = 0, x = 5, y = 5;
    for(int i=0;i<4;i++) dir[d[i]-'A'] = i;
    for(int i=0; i<dirs.size(); i++) {
        int nx = x + dx[dir[dirs[i]-'A']];
        int ny = y + dy[dir[dirs[i]-'A']];
        if(nx < 0 || ny < 0 || nx >= 11 || ny >= 11) continue;
        if(!visit[x][y][nx][ny]) answer++;
        visit[x][y][nx][ny] = visit[nx][ny][x][y] = true;
        x = nx;
        y = ny;
    }
    return answer;
}

/*
지나갔던 경로들을 기억해주었습니다.
*/