/*
스트림으로 흘러오는 값을 일단 모두 push 해줍니다.
스트림과 target의 값이 일치할 때, target과 일치하지않는 push되어 있던 값들을 모두 pop 해줍니다.
target은 다음 인덱스를 바라봅니다.
*/

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        for(int i=1, j = 0; i<=n && j < target.size(); i++) {
            if(target[j] == i) {
                int diff = target[j] - (j ? target[j - 1] : 0) - 1;
                while(diff--) res.push_back("Pop");
                j++;
            }
            res.push_back("Push");
        }
        return res;
    }
};
