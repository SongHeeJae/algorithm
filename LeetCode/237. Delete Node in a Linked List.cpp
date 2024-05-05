/*
singly-linked list에서 node를 제거해야하지만, 메모리에서의 제거를 의미하는 것은 아닙니다.
node의 이전 포인터를 모르므로, node의 다음 포인터에 있는 val과 next를 node로 가져오면 됩니다.
*/

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
