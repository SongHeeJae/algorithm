/*
리스트를 순회하면서 k번째 노드를 찾아줍니다.
k번째 노드에서부터 (n-k)개의 리스트를 마저 순회할 수 있습니다.
이를 이용하여 (n-k)번째 노드도 찾아줍니다.
*/

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *cur = head, *left = NULL, *right = head;
        while(--k) cur = cur->next;

        left = cur;
        cur = cur->next;

        while(cur) {
            cur = cur->next;
            right = right->next;
        }

        swap(left->val, right->val);

        return head;
    }
};
