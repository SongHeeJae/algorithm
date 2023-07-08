class Solution {
public:
    int count(string& a, int k, char c) {
        int j = 0, cnt = 0;
        for(int i = 0; i<a.size(); i++) {
            cnt += a[i] == c;
            if(cnt > k) cnt -= a[j++] == c; 
        }
        return a.size() - j;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(
            count(answerKey, k, 'T'), count(answerKey, k, 'F')
        );
    }
};
