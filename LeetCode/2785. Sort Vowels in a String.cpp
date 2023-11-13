/*
카운트 정렬을 이용하여 풀었습니다.
자음은 원 위치 그대로, 모음은 대문자 우선/내림차순으로 정렬되어야합니다.
s에 나타난 모든 모음의 개수를 구해줍니다.
s가 자음이라면, t에 넣어줍니다.
s가 모음이라면, 'A'부터 'z'까지 처음으로 카운트가 남아있는 위치를 찾아주고, 해당 모음의 카운트는 차감해줍니다.
*/

class Solution {
public:
    string sortVowels(string s) {
        int cnt['z' + 1] = {0};
        for(char c : s) 
            if(isVowel(c)) cnt[c]++;

        string t = "";
        char cur = 'A';
        for(char c : s) {
            if(isVowel(c)) {
                while(cur <= 'z' && cnt[cur] <= 0) cur++;
                t.push_back(cur);
                cnt[cur]--;
            } else {
                t.push_back(c);
            }
        }

        return t;
    }

private:
    bool isVowel(char c) {
        return c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U'; 
    }
};
