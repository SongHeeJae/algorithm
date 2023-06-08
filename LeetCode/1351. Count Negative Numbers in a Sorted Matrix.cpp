/*
행과 열 모두 내림차순으로 정렬되어 있는 점을 이용하면 O(n + m) 시간으로 풀 수 있습니다.
우측 상단 지점부터 좌측으로 이동하면서, 처음으로 0 또는 양수가 나오는 지점을 찾아줍니다.
그러면 우측에 있는 모든 수는 음수입니다.
다음 행으로 이동해주고, 여기에서도 우측에 있는 모든 수는 음수입니다.
좌측으로 이동하면서, 처음으로 0 또는 양수가 나오는 지점을 찾아줍니다.
그러면 우측에 있는 모든 수는 음수입니다.
마지막 행까지 반복해줍니다.
*/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int j = m - 1, cnt = 0;
        for(int i=0; i < n; i++) {
            while(j >= 0 && grid[i][j] < 0) j--;
            cnt += m - 1 - j;
        }
        return cnt;
    }
};


/*
단일 반복문으로 바꿔주었습니다.
*/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int i = 0, j = m - 1, cnt = 0;
        while(i < n) {
            if (j >= 0 && grid[i][j] < 0) j--;
            else {
                cnt += m - 1 - j;
                i++;
            }
        }
        return cnt;
    }
};
