/*
스택을 이용하여 풀 수 있었습니다.
일단 asteroid를 스택에 담아줍니다.
스택에 2개 이상이 담겨있으면, 충돌이 일어날 여지가 있습니다.
스택의 top이 왼쪽으로 이동(음수)하고, 나머지가 오른쪽으로 이동(양수)하면, 충돌이 일어납니다.
스택에서 2개의 asteroid t1과 t2를 차례대로 꺼내줍니다.
asteroid t1과 t2의 크기는 sz1, sz2입니다.
sz1 == sz2라면, 둘 다 소멸합니다.
sz1 < sz2라면, t1만 소멸합니다.
sz1 > sz2라면, t2는 소멸되고, t1은 스택의 나머지 asteroid에서 다음으로 충돌 될 수 있는 asteroid을 찾습니다.
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for(int ast : asteroids) {
            res.push_back(ast);
            while(res.size() > 1) {
                int t1 = res[res.size() - 1];
                int t2 = res[res.size() - 2];
                if(t1 > 0 || t2 < 0) {
                    break;
                }
                res.pop_back(); res.pop_back();
                int sz1 = abs(t1), sz2 = t2;
                if(sz1 > sz2) res.push_back(t1);
                else {
                    if(sz1 < sz2) res.push_back(t2);
                    break;
                }
            }
        }
        return res;
    }
};
