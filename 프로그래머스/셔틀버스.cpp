#include <string>
#include <vector>
#include <cstdlib>
#include <queue>
using namespace std;

int times[60 * 24] = {0};

int convertTimeToSeconds(string s) {
    return atoi(s.substr(0, 2).c_str()) * 60 +
        atoi(s.substr(3).c_str());
}

string convertSecondsToTime(int t) {
    char buf[10];
    sprintf(buf, "%02d:%02d", t/60, t%60);
    return string(buf);
}

string solution(int n, int t, int m, vector<string> timetable) {
    for(auto tt : timetable)
        times[convertTimeToSeconds(tt)]++;
    queue<int> q;
    int cnt = 0; // 버스 출발 횟수
    int num = 0; // 탑승자
    int start = 60 * 9; // 버스 출발 시간
    int prev = -1; // 마지막에 탄 사람의 탑승 시간
    int i; // i는 현재 흘러가는 시간
    for(i=0; i<60*24; i++) {
        if(times[i] > 0) {
            while(times[i]) {
                if(num == m) break; // 정원 초과
                prev = i;
                num++;
                times[i]--;
            }
            while(times[i]--) q.push(i); // 큐에서 대기
        }
        if(i == start) { // 버스 출발
            cnt++; // 출발 횟수 + 1
            if(cnt == n) break; // 더이상 올 버스 없음
            num = 0; // 탑승자 0명 초기화
            start += t;// 다음 버스 출발 시간
            while(!q.empty() && num != m) { // 대기 인원 탑승
                prev = q.front();
                q.pop();
                num++;
            }
        }
    }
    if(prev == -1 || num < m) { // 앞에 탄 사람이 없거나 정원 여유 있는 경우
        // i 그대로 출력. 마지막 출발 탑승
        return convertSecondsToTime(i);
    } else {
        // 정원 여유 없는 경우 앞자리 빼앗음
        return convertSecondsToTime(prev - 1);
    }
}