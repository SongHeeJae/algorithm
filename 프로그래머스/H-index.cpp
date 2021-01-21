#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    for(int i=0; i<citations.size(); i++)
        if(citations.size() - i <= citations[i])
            return citations.size() - i;
    return 0;
}

/*

먼저 정렬합니다.

[0, 1, 3, 5, 6]
0번 이상 인용된 논문은 5개입니다.
1번 이상 인용된 논문은 4개입니다.
3번이상 인용된 논문은 3개입니다.

[1, 8, 9, 10, 11, 12]
1번 이상 인용된 논문은 6개입니다.
8번 이상 인용된 논문은 5개입니다.
9번 이상 인용된 논문은 4개입니다.

x번 이상 인용된 논문은 y개입니다.
x >= y 시점의 y개가 H-index입니다.

*/