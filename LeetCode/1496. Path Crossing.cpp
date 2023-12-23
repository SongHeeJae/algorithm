/*
이미 방문한 좌표를 기억해줍니다.
*/

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<int> v;
        int x = 0, y = 0;
        v.insert(x * 10000 + y);
        for(char p : path) {
            if(p == 'N') {
                x--;
            } else if(p == 'S') {
                x++;
            } else if(p == 'E') {
                y++;
            } else {
                y--;
            }
            if(v.find(x * 10000 + y) != v.end()) return true;
            v.insert(x * 10000 + y);
        }
        return false;
    }
};
