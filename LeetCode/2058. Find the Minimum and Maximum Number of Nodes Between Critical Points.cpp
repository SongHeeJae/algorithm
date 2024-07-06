/*
마지막 크리티컬 포인트와 첫 크리티컬 포인트 사이의 거리가 maximum distance,
현재 크리티컬 포인트와 이전 크리티컬 포인트 사이의 minimum distance 입니다.
링크드리스트를 순회하며 위 값을 구해줍니다.
*/

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *cur = head, *prv = NULL;
        int curIdx = 0, startIdx = -1, lastIdx = -1;
        int minDistance = INT_MAX;
        while(cur) {
            if(isCriticalPoint(prv, cur, cur->next)) {
                if(startIdx == -1) startIdx = curIdx;
                if(lastIdx != -1) minDistance = min(minDistance, curIdx - lastIdx);
                lastIdx = curIdx;
            }
            curIdx++;
            prv = cur;
            cur = cur->next;
        }
        if (startIdx == lastIdx) {
            return {-1, -1};
        }
        return {minDistance, lastIdx - startIdx};
    }

    bool isCriticalPoint(ListNode* prv, ListNode* node, ListNode* nxt) {
        if(!prv || !nxt) return false;
        return node->val > prv->val && node->val > nxt->val
            || node->val < prv->val && node->val < nxt->val;
    }
};
