#include <iostream>
#include <vector>
using namespace std;
int solution(int n, vector<int> stations, int w)
{
    int answer = 0, start = 1, end, cw = w * 2 + 1;
    stations.push_back(n + w + 1); // 마지막 누락된 범위도 구해주기 위함
    for(int i=0; i<stations.size(); i++) {
        end = stations[i] - w - 1;
        answer += (end - start + 1.0) / cw + 0.999999; // 올림처리
        start = stations[i] + w + 1;
    }
    return answer;
}

/*
stations 배열을 이용해 전파가 전달되지 않는 아파트의 시작범위와 끝범위를 구해주며, 해당 범위를 커버할 수 있는 기지국의 개수를 구해주었습니다.
만약 전파의 도달 거리가 W라면, 기지국은 W * 2 + 1만큼의 범위를 커버할 수 있습니다.
따라서, (전파가 도달되지 않는 범위) / (W * 2 + 1)을 올림 처리하면, 해당 범위를 커버할 수 있는 기지국의 개수입니다.
*/