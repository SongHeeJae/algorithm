#include <string>
#include <vector>

using namespace std;

bool visit[200] = {false};

void dfs(int computer, vector<vector<int>>& computers) {
    visit[computer] = true;
    for(int i=0; i < computers[computer].size(); i++) {
        if(computers[computer][i] == 1 && !visit[i]) {
            dfs(i, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0; i < n; i++) {
        if(!visit[i]) {
            dfs(i, computers);
            answer++;
        }
    }
    return answer;
}