#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    while(n != 0) {
        if(n % 2 == 0) n /= 2;
        else n--, ans++;
    }
    return ans;
}

/*
순간 이동할 수 있는 지점이라면, 순간 이동 해줍니다.
그렇지 않다면, 건전지를 1만큼 사용하여 다음 위치로 이동합니다.
*/