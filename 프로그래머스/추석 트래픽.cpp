#include <string>
#include <vector>
using namespace std;

pair<int, int> getStartEndMilliSeconds(string& time) {
    int h = atoi(time.substr(11, 2).c_str());
    int m = atoi(time.substr(14, 2).c_str());
    int s = atof(time.substr(17, 6).c_str()) * 1000;
    string temp = time.substr(24);
    temp.pop_back();
    int t = atof(temp.c_str()) * 1000;
    int end = (h * 3600 + m * 60) * 1000 + s;
    int start = end - t + 1;
    return {start, end};
}

int solution(vector<string> lines) {
    int max = 0;
    vector<pair<int, int>> times;
    for(auto line : lines) {
        times.push_back(getStartEndMilliSeconds(line));
    }
    
    for(int i=0;i<times.size(); i++) {
        int cnt = 0;
        int end = times[i].second;
        for(int j=i; j<times.size(); j++) {
            if(times[j].first - end < 1000)
                cnt++;
        }
        if(cnt > max) max = cnt;
    }
    return max;
}

/*
먼저 각 로그 시간들을 정수 형태로 바꿔주었습니다.

그 후 응답 완료 시간을 기준으로 1초 내에 처리되는 요청인지 확인하였습니다.
*/