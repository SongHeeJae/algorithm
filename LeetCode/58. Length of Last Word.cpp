/*
끝에서부터 순회하면서 처음 나오는 공백은 모두 무시하여 단어의 끝 인덱스를 구해주고,
해당 지점부터 새로운 공백이 나올 때까지 순회하여 단어의 시작 인덱스를 구해줍니다.
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int start = s.size() - 1;
        while(s[start] == ' ') start--;
        int end = start;
        while(end >= 0 && s[end] != ' ') end--;
        return start - end;
    }
};
