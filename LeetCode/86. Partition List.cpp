/*
x 미만의 값들로 이루어진 파티션, x 이상의 값들로 이루어진 파티션을 분리하여 각각의 리스트로 만들어줍니다.
두 개의 파티션을 하나로 연결해주면 됩니다.
*/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *p1 = NULL, *p2 = NULL, *h1 = NULL, *h2 = NULL;

        for(ListNode* cur = head; cur; cur = cur->next) {
            if(cur->val < x) {
                if(h1) {
                    p1->next = cur;
                    p1 = p1->next;
                } else {
                    p1 = h1 = cur;
                }
            } else {
                if(h2) {
                    p2->next = cur;
                    p2 = p2->next;
                } else {
                    p2 = h2 = cur;
                }
            }
        }

        if(p1) p1->next = h2;
        if(p2) p2->next = NULL;
        
        return h1 ? h1 : h2;
    }
};

