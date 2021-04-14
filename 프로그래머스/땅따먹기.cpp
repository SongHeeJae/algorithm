#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int n = land.size();
    for(int i=1; i<n; i++) {
        for(int j=0; j<4; j++) {
            int m = -1;
            for(int k=0; k<4; k++)
                if(j != k) m = max(m, land[i-1][k]);
            land[i][j] += m;
        }
    }
    return max({land[n-1][0], land[n-1][1], land[n-1][2], land[n-1][3]});
}

/*
현재 행은 이전 행의 동일한 열에서는 밟을 수 없습니다.
지금 밟을 수 있는 칸까지 누적된 최대 점수는,
dp[i][j] = max(
  dp[i-1][0~3 중에서 j가 아닌 수)]
);
(i는 행 번호(0~n-1), j는 열 번호(0~3))
입니다.
*/