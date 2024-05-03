/*
두 문자열에서 '.'이 나올 때까지 version integer를 구하여 비교해줍니다.
모든 '.'을 판별할 때까지 수행해줍니다.
*/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int startIdx1 = 0, startIdx2 = 0;
        while(startIdx1 < version1.size() || startIdx2 < version2.size()) {
            int endIdx1 = findDotOrEndIdx(version1, startIdx1);
            int endIdx2 = findDotOrEndIdx(version2, startIdx2);
            int v1 = findVersion(version1, startIdx1, endIdx1);
            int v2 = findVersion(version2, startIdx2, endIdx2);
            if(v1 < v2) return -1;
            else if(v1 > v2) return 1;
            startIdx1 = endIdx1 + 1;
            startIdx2 = endIdx2 + 1;
        }
        return 0;
    }

    int findDotOrEndIdx(string& str, int startIdx) {
        for(int i=startIdx; i<str.size(); i++) {
            if(str[i] == '.') return i;
        }
        return str.size();
    }

    int findVersion(string& ver, int startIdx, int endIdx) {
        int v = 0;
        for(int i=startIdx; i<endIdx; i++) {
            v = v * 10 + (ver[i] - '0');
        }
        return v;
    }
};
