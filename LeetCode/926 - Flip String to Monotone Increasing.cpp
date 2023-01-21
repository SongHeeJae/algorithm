/*
바이너리 스트링을 최소 횟수로 증가하는 형태로 만들어주어야합니다.
스트링을 순차적으로 탐색하면서 1이 나오는 횟수를 구해줍니다.
0일 때는, 지금까지의 1을 0으로 flip 했을 때의 횟수(지금까지 1이 나온 횟수)와 지금의 0을 1로 flip했을 때의 횟수 중,
더 작은 값을 현재까지의 최소 횟수에 업데이트해줍니다.
*/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int res = 0, cnt = 0;
        for(char c : s) {
            if(c == '0') res = min(cnt, ++res);
            else cnt++;
        }
        return res;   
    }
};
