#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int getNumCount(int num) {
    int cnt = 0;
    for(;num!=0; num/=10)cnt++;
    return cnt;
}

int solution(string s) {
    int len = s.length();
    int answer = len;
    for(int i=1; i<=len / 2; i++) {
        int tlen = len, cnt = 1;
        bool flag = false;
        string prev = s.substr(0, i);
        for(int j=i; j<=len; j+=i) { // 누락된 마지막 검사 위해 <= len까지 수행
            string cur = s.substr(j, i);
            if(cur == prev) cnt++, flag = true;
            else {
                if(flag) tlen -= i*(cnt-1) - getNumCount(cnt);
                cnt = 1;
                flag = false;
            }
            prev = cur;
        }re
        answer = min(answer, tlen);
    }
    return answer;
}

/*
각 길이 별로 잘랐을 때, 압축되는 길이들의 최솟값을 구해주면 됩니다.
처음에 한 가지 놓친게 있었는데, 압축된 길이를 표시하는 숫자의 자릿 수도 염두에 두어야합니다.
*/