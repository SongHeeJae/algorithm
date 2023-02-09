/*
슬라이딩 윈도우 문제였습니다.
순차적으로 탐색하면서 과일을 선택하고, 유효한 과일 선택 범위의 윈도우를 관리해줍니다.
선택된 과일의 종류가 2개를 넘어가면, 좌측 윈도우를 1칸 좁혀줍니다.
변하는 윈도우의 크기에서 가장 큰 값을 구해줍니다.
*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> choiced;
        int res = 0;
        for(int i=0, j=0; i<fruits.size(); i++) {
            choiced[fruits[i]]++;
            if(choiced.size() > 2) {
                if(--choiced[fruits[j]] == 0) {
                    choiced.erase(fruits[j]);
                }
                j++;
            }
            res = max(res, i - j + 1);
            
        }
        return res;
    }
};
