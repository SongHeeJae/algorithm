/*
먼저 모든 카드를 왼쪽에서만 골랐을 때의 합을 구해줍니다.
이 값으로 합의 최댓값을 초기화해줍니다.
다음으로, 왼쪽에서 골랐던 카드를 하나씩 제거하며 오른쪽 카드를 선택해줍니다. 이 과정에서 최댓값을 업데이트해줍니다.
이를 통해 k번 반복으로 합의 최댓값을 구해낼 수 있습니다.
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sz = cardPoints.size();
        int sum = 0;
        for(int i=0; i<k; i++) sum += cardPoints[i];
        
        if(k == sz) return sum;
        
        int res = sum;
        for(int i=0; i<k; i++) {
            sum = sum - cardPoints[k - 1 - i] + cardPoints[sz - 1 - i];
            res = max(res, sum);
        }
        return res;
    }
};
