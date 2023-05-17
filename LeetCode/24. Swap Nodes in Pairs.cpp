/*
두 개의 노드를 스왑해주고, 스왑된 우측 노드를 이전 노드로 기억해줍니다.
다음 두 개의 노드를 스왑해주고, 이전 노드의 다음 노드를, 스왑된 좌측 노드로 기억해줍니다.
*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *cur = head, *prv = NULL;
        ListNode *res = head && head->next ? head->next : head; 
        while(cur && cur->next) {
            ListNode* nxt = cur->next->next;
            if(prv) prv->next = cur->next;
            cur->next->next = cur;
            cur->next = nxt;
            prv = cur;
            cur = nxt;
        }
        return res;
    }
};
