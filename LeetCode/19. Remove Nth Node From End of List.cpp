/*
두 개의 포인터를 유지해줍니다.
포인터 하나는 n번 만큼 미리 이동해줍니다.
그리고 해당 포인터가 끝에 도달할 때까지, 두 포인터를 같이 이동시켜줍니다.
이를 통해 (list size - n)번 이동하게 되고, 뒤늦게 이동한 포인터는 뒤에서 n번째 노드를 찾을 수 있습니다.
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head, *fast = head;
        for(int i=0; i<n; i++) fast = fast->next;
        if(!fast) return head->next;
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
