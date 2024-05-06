/*
재귀를 이용하여 풀었습니다.
리스트의 마지막 노드를 먼저 방문해주고, 이후 방문되는 이전 노드의 값이 더 작으면 제거해줍니다.
*/

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        return removeNodes(head, NULL);
    }

    ListNode* removeNodes(ListNode* cur, ListNode* prv) {
        if(!cur) return prv;
        ListNode* res = removeNodes(cur->next, cur);
        if(cur->val < res->val) {
            if(prv) prv->next = res;
            return res;
        } else {
            return cur;
        }
    }
};
