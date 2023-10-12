/*
MountainArray.get은 100회의 콜을 넘어가면 안됩니다.
mountrain array는 가장 큰 값을 기준으로 오름차순/내림차순 정렬되어있기 때문에, binary search를 이용하여 로그 시간에 해결할 수 있었습니다.
가장 큰 값을 찾아주고, 해당 값 기준 좌우측 범위에서 target을 탐색해줍니다.
*/

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int m = findMid(mountainArr);
        int res = bsearch(target, mountainArr, 0, m);
        if (res != -1) {
            return res;
        }
        return bsearchReverse(target, mountainArr, m + 1, mountainArr.length() - 1);
    }
private:
    int findMid(MountainArray &mountainArr) {
        int s = 0, e = mountainArr.length() - 1;
        while(s < e) {
            int m = (s + e) / 2;
            if(mountainArr.get(m) < mountainArr.get(m + 1)) {
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        return s;
    }

    int bsearch(int target, MountainArray &mountainArr, int s, int e) {
        while(s <= e) {
            int m = (s + e) / 2;
            if(mountainArr.get(m) == target) return m;
            else if(mountainArr.get(m) < target) s = m + 1;
            else e = m - 1;
        }
        return -1;
    }

    int bsearchReverse(int target, MountainArray &mountainArr, int s, int e) {
        while(s <= e) {
            int m = (s + e) / 2;
            if(mountainArr.get(m) == target) return m;
            else if(mountainArr.get(m) > target) s = m + 1;
            else e = m - 1;
        }
        return -1;
    }
};
