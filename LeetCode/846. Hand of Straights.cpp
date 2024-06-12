/*
트리맵에 각 카드의 개수를 저장해줍니다.
트리의 첫번째 요소(가장 작은 값)를 꺼내고, groupSize만큼 연이은 카드가 남아있는지 검사해줍니다.
다 사용된 카드는 제거하고, 트리맵에서 제거해줍니다.
*/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> cardToCnt;
        for(int card : hand) {
            cardToCnt[card]++;
        }
        
        while(!cardToCnt.empty()) {
            int card = cardToCnt.begin()->first;
            for(int i=0; i<groupSize; i++) {
                int& cnt = cardToCnt[card + i];
                if(cnt == 0) return false;
                if(--cnt == 0) cardToCnt.erase(card + i);
            }
        }
        return true;
    }
};
