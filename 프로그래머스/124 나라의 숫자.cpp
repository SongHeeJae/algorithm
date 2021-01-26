#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n) {
    string answer = "";
    char v[] = "412";
    while(n != 0) {
        int r = n % 3;
        if(!r) n--; 
        answer.push_back(v[r]);
        n /= 3;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}


/*
모듈러 연산을 이용하였습니다. 3의 배수라면 1을 빼주었습니다.
*/