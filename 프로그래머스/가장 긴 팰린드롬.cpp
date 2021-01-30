#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int solution(string s)
{
    int answer = 1;
    int dp[2500][2500] = {0};
    
    for(int i=0; i<s.size(); i++) {
        dp[i][i] = 1;
    }
    
    for(int i=0; i<s.size()-1; i++) {
        if(s[i] == s[i+1]) {
            dp[i][i+1] = 1;
            answer = 2;
        }
    }
    
    for(int i=2; i<s.size(); i++) {
        for(int j=0; j<s.size() - i; j++) {
            if(s[j] == s[j+i] && dp[j+1][j+i-1] == 1) {
                dp[j][j+i] = 1;
                answer = i+1;
            }
        }
    }
    return answer;
}

/*
dp[i][j]는 i~j 범위가 팰린드롬이라면 1, 그렇지 않다면 0입니다.
"abcba"가 있을때,
"c"가 팰린드롬이고, 양 옆에 문자 "b"가 같으므로 "bcb"는 팰린드롬입니다.
"bcb"가 팰린드롬이고, 양 옆에 문자 "a"가 같으므로 "abcba"는 팰린드롬입니다.
홀의 자릿수와 짝의 자릿수인 문자열의 팰린드롬 여부를 구하기 위해,
한 자릿수와 두 자릿수에 대한 팰린드롬을 먼저 구해준 뒤, 모든 팰린드롬 여부를 구해주었습니다.
*/