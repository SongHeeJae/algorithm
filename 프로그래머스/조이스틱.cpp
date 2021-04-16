#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int moveNext(int cur, bool right, int len) {
    return right ? (cur + 1) % len : (cur + len - 1) % len;
}

int solution(string name) {
    int cnt[26] = {0}, cur = 0, len = name.size(), answer = 0;
    for(int i=0; i<26; i++) cnt[i] = min(i, 26 - i);  
    while(1) {
        bool right = true;
        int dist = 0;
        for(; dist<len; dist++) {
            if(name[(cur + dist) % len] != 'A') break;
            if(name[(cur - dist + len) % len] != 'A') {
                right = false;
                break;
            }
        }
        if(dist == len) break;
        answer += dist;
        while(1) {
            answer += cnt[name[cur] - 'A'];
            name[cur] = 'A';
            if(dist-- == 0) break;
            cur = moveNext(cur, right, len);
        }
    }
    return answer;
}

/*
먼저 각 알파벳을 뽑을 수 있는 최소 횟수를 초기화 해줍니다.
그 후, 현재 위치에서 아직 값을 변경 안했으면서 'A'가 아닌 가장 가까운 위치를 찾아줍니다.
해당 위치로 커서를 이동하면서 조작 횟수를 업데이트해줍니다.
업데이트한 위치는 'A'로 값을 변경해서 방문 표시해줍니다.
*/