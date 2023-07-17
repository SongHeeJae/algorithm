/*
2개의 스택에 각 리스트의 모든 값을 담아줍니다.
스택에 담긴 값을 이용하여 각 수의 합을 구하고, 뒤집어진 리스트로 만들어줍니다.
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stk1, stk2;
        while(l1) stk1.push(l1->val), l1 = l1->next;
        while(l2) stk2.push(l2->val), l2 = l2->next;

        int s = 0;
        ListNode* res = NULL;
        while(!stk1.empty() || !stk2.empty()) {
            if(!stk1.empty()) s += stk1.top(), stk1.pop();
            if(!stk2.empty()) s += stk2.top(), stk2.pop();
            ListNode* node = new ListNode(s % 10);
            if(res) node->next = res;
            res = node;
            s = s / 10;
        }

        if(s) {
            ListNode* node = new ListNode(s);
            node->next = res;
            res = node;
        }

        return res;
    }
};
