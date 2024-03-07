/*
2개의 포인터를 각각 한 칸, 두 칸씩 이동해줍니다.
두 칸씩 이동한 포인터가 끝에 도달하면, 한 칸씩 이동한 포인터가 중간이 됩니다.
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
