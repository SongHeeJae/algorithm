#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool chk[100001] = {false};

bool comp(string& a, string& b) {
    return a.size() < b.size();
}

vector<string> split1(string s) {
    vector<string> arr;
    int idx = 0;
    for(int i=1; i<s.size(); i++) {
        if(s[i-1] == '}' && s[i] == ',') {
            arr.push_back(s.substr(idx, i - idx));
            idx = i + 1;
        }
    }
    arr.push_back(s.substr(idx));
    return arr;
}

vector<int> split2(string s) {
    vector<int> arr;
    int idx = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == ',') {
            arr.push_back(stoi(s.substr(idx, i - idx)));
            idx = i + 1;
        }
    }
    arr.push_back(stoi(s.substr(idx)));
    return arr;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> res1 = split1(s.substr(1, s.size() - 2));
    sort(res1.begin(), res1.end(), comp);
    for(auto ss : res1) {
        vector<int> res2 = split2(ss.substr(1, ss.size() - 2));
        for(auto i : res2) {
            if(!chk[i]) answer.push_back(i);
            chk[i] = true;
        }
    }
    return answer;
}

/*
먼저 { }별로 나눠서 문자열 길이의 오름차순으로 정렬해줍니다.
그 후, { }별로 나뉜 문자열에서 숫자 값을 뽑아내줍니다.
이미 방문한 숫자라면 그냥 넘어가고, 방문하지 않은 숫자라면 answer에 담아줍니다.
*/