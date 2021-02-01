#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

int arr[99 * 60 * 60 + 59 * 60 + 59 + 1] = {0};

int convertTimeToSeconds(string time) {
    int seconds = 0;
    seconds += atoi(time.substr(0, 2).c_str()) * 60 * 60;
    seconds += atoi(time.substr(3, 2).c_str()) * 60;
    seconds += atoi(time.substr(6).c_str());
    return seconds;
}

string convertSecondsToTime(int seconds) {
    char time[20];
    int t = seconds/3600;
    int m = (seconds%3600)/60;
    int s = seconds%3600%60;
    sprintf(time, "%02d:%02d:%02d", t, m, s);
    return string(time);
}

string solution(string play_time, string adv_time, vector<string> logs) {
    if(play_time == adv_time) return convertSecondsToTime(0);
    for(int i=0; i<logs.size(); i++) {
        int start = convertTimeToSeconds(logs[i].substr(0, 8));
        int end = convertTimeToSeconds(logs[i].substr(9));
        for(int j=start; j<end; j++) {
            arr[j]++;
        }
    }
    
    int play_seconds = convertTimeToSeconds(play_time);
    int adv_seconds = convertTimeToSeconds(adv_time);
    long long sum = 0;
    for(int i=0; i<adv_seconds; i++) sum += arr[i];
    long long maxSum = sum;
    int answer = 0;
    for(int i=adv_seconds; i<play_seconds; i++) {
        sum += arr[i] - arr[i-adv_seconds]; // 왼쪽 없애고 오른쪽 새로운 것 추가
        if(sum > maxSum) {
            maxSum = sum;
            answer = i - adv_seconds + 1;
        }
    }
    return convertSecondsToTime(answer);
}

/*
먼저 초 단위로 다 변환해준 뒤, 각 초마다 각 로그의 시청 횟수를 구해줬습니다.
그리고 광고 시간의 범위를 갖는 최대 값 범위를 찾아주었습니다.
*/