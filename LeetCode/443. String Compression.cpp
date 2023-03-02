/*
투포인터를 두고 풀었습니다.
하나의 포인터는 chars를 순차적으로 탐색하면서 연속된 동일 문자 개수를 구해주고,
또 다른 포인터는 새로운 문자가 나오면 chars에 압축 내역을 반영해주었습니다.
*/

class Solution {
public:
    int compress(vector<char>& chars) {
        chars.push_back('?'); // dummy

        char ch = chars[0];
        int cnt = 1;
        int j = 0;
        for(int i=1; i<chars.size(); i++) {
            if(chars[i] != ch) {
                chars[j++]= ch;
                if(cnt >= 10) {
                    string cntStr = to_string(cnt);
                    for(char cntCh : cntStr) {
                        chars[j++] = cntCh;
                    }
                } else if(cnt > 1) {
                    chars[j++] = cnt + '0';
                }
                cnt = 0;
                ch = chars[i];
            }
            cnt++;
        }

        return j;
    }
};
