#include <string>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

string words = "ACFJMNRT";
int pos[26];

bool check(char a, char b, char c, int n) {
    int val = abs(pos[a - 'A'] - pos[b - 'A']) - 1;
    if(c == '<') return val < n;
    else if(c == '>') return val > n;
    else return val == n;
}

int dfs(vector<string>& data, int idx) {
    if(idx == words.size()) return 1;
    int c = 0;
    for(int i=0; i<words.size(); i++) {
        if(pos[words[i] - 'A'] != -1) continue;
        pos[words[i]-'A'] = idx;
        int j;
        for(j=0; j<data.size(); j++) {
            if(pos[data[j][0] - 'A'] == -1 || pos[data[j][2] - 'A'] == -1) continue;
            if(!check(data[j][0], data[j][2], data[j][3], data[j][4]-'0')) {
                break;
            }
        }
        if(j == data.size()) {
            c += dfs(data, idx + 1);
        }
        pos[words[i]-'A'] = -1;
    }
    return c;
}

int solution(int n, vector<string> data) {
    memset(pos, -1, sizeof(pos));
    return dfs(data, 0);
}

/*
조건을 만족하는 모든 경우의 수를 만들어주었습니다.
각 인원을 배치한 위치를 기억해주고, 조건을 만족한다면 이어서 다음 사람들을 배치해주었습니다.
*/