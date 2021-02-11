#include <vector>
using namespace std;

int weaks[201] = {0}; // 취약점 위치
bool visit[8] = {false};
int answer = -1;
vector<int> friends;

bool isPossible(int n, vector<int>& weak) {
    for(int i=0; i<weak.size(); i++) {
        int fidx = 0, size = 0;
        for(int j=0; j < n && fidx < friends.size(); j++) {
            if(weaks[(weak[i] + j) % n]) {
                for(int k=0; k<=friends[fidx]; j++, k++)
                    if(weaks[(weak[i] + j) % n]) size++;
                j--; fidx++;
            }
        }
        if(size == weak.size()) return true;
    }
    return false;
}

void dfs(vector<int>& dist, int n, vector<int>& weak, int depth, int num) {
    if(answer != -1) return;
    if(depth == num) {
        if(isPossible(n, weak)) answer = friends.size();
        return;
    }
    
    for(int i=depth; i< dist.size(); i++) {
        if(visit[i]) continue;
        visit[i] = true;
        friends.push_back(dist[i]);
        dfs(dist, n, weak, depth + 1, num);
        visit[i] = false;
        friends.pop_back();
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    for(int w : weak) weaks[w] = 1; // 취약점 위치 초기화
    for(int i=1; i<=dist.size(); i++)
        dfs(dist, n, weak, 0, i);
    return answer;
}

/*
1명, 2명, 3명, ... 처럼 최소 친구 수부터 순서와 상관 없이 중복 없이 만들 수 있는 모든 거리의 경우의 수를 구해준 다음에,
각 친구들이 각 취약점의 시작점 위치에서부터 외벽을 점검해나갈 때 모든 취약점을 점검할 수 있는지 확인하였습니다.

예를 들어, [1, 2, 5]인 친구들이 있다면

[1]
[2]
[5]
[1, 2]
[1, 5]
[2, 5]
[1, 2, 5]

7가지의 경우의 수가 나오고, 이를 이용하여 모든 취약점을 점검할 수 있는지 확인하였습니다.
*/