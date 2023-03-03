/*
O(n + m) 알고리즘을 직접 작성해도 되겠지만.. 손쉽게 STL을 사용하여 풀어주었습니다.
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        auto idx = haystack.find(needle);
        return idx == string::npos ? -1: idx;
    }
};
