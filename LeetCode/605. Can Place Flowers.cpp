/*
연속된 0의 개수를 구하여, 심을 수 있는 꽃의 개수를 계산해줍니다.
꽃 사이의 지점은, 2개의 꽃 양 옆 2칸을 사용할 수 없지만,
시작과 끝 지점은, 1개의 꽃 옆 1칸만 사용할 수 없음을 인지하면 됩니다.
*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int zc = 0;
        bool showOne = false;
        for(int f : flowerbed) {
            if(f == 1) {
                n -= (zc - showOne) / 2;
                zc = 0;
                showOne = true;
            } else {
                zc++;
            }
        }
        return showOne ? 
            n <= zc / 2 :
            n <= flowerbed.size() / 2 + flowerbed.size() % 2;
    }
};
