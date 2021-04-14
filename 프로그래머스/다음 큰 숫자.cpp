#include <string>
#include <vector>

using namespace std;

int countOne(int num) {
    int cnt = 0;
    while(num != 0) {
        if(num & 1) cnt++;
        num = num >> 1;
    }
    return cnt;
}

int solution(int n) {
    int i = n + 1;
    for(int c = countOne(n); c != countOne(i); i++);
    return i;
}

/*
n을 이진수로 변환했을 때 1의 개수를 구해준 뒤, n + i(i > 0)를 이진수로 변환했을 때의 1의 개수와 동일하다면, 다음 큰 숫자입니다.
*/