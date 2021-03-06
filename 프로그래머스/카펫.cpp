#include <string>
#include <vector>
using namespace std;
vector<int> solution(int brown, int yellow) {
    int n = brown + yellow, h = 0;
    while(h++)
        if(n % h == 0 && (n / h + h) * 2 - 4 == brown) return {n / h, h};
}

/*
주어진 칸의 개수로 가능한 모든 가로, 세로 길이에 대하여 검사해주었습니다.

재미삼아 줄이긴했는데,
while(h++); 문법은 h가 0부터 시작이라 그냥 바로 종료될줄 알았는데 왜 되는지 모르겠네요.

vector<int> solution(int brown, int yellow) {
    int n = brown + yellow, h = 0;
    while(h++)
        if(n % h == 0 && (n / h + h) * 2 - 4 == brown) return {n / h, h};
    return {};
}

원래 작동하지 않는 코드가 맞는데, 밑에 return {}를 달아보니깐 while문이 작동하지 않네요.
return할 곳이 없어서 컴파일러가 그냥 실행시키나봅니다. 추측입니다.
답이 확실히 있는 문제라 짜긴 한거고 제 코드가 문제 있는 게 맞긴한데 저래도 되는건지는 좀 이상합니다.

*/