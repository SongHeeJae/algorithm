#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, int s) {
    if(s / n == 0) return vector<int>(1, -1);
    vector<int> answer(n, s / n);
    for(int i=n-1, j = s % n; j > 0; i--, j--) answer[i]++;
    return answer;
}

/*
s / n이면, n개의 수로 s를 만들 수 없습니다.
만들 수 있다면, 최대한 큰 값으로 수의 집합을 만들어야하므로 n개의 수를 s / n으로 초기화해줍니다.
그리고 남은 s % n라는 수를 그 크기만큼 뒤에서부터(정렬하지 않아도 되므로) 1씩 더해주면 됩니다.
*/