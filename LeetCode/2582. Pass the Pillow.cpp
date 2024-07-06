/*
(2 * n - 2)초가 지날 때마다 pillow는 첫번째 사람에게 돌아오므로 (time % (2 * n - 2))번만 확인해줘도 됩니다.
해당 값이 n - 1 이하라면 정방향 이동, 초과라면 역방향 이동입니다.
*/

class Solution {
public:
    int passThePillow(int n, int time) {
        time = time % (2 * n - 2);
        return time <= n - 1 ? time + 1 : n + n - time - 1;
    }
};

