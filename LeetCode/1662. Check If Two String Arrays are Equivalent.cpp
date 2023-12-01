/*
word1과 word2의 문자를 하나씩 탐색하며 비교해줍니다.
*/

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i=0, ii=0, j=0, jj=0;
        while(i < word1.size() && j < word2.size()) {
            if(word1[i][ii] != word2[j][jj]) {
                return false;
            }

            ii++, jj++;

            if(ii == word1[i].size()) {
                ii = 0;
                i++;
            }
            if(jj == word2[j].size()) {
                jj = 0;
                j++;
            }
        }

        return i == word1.size() && j == word2.size();
    }
};
