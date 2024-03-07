/*
투포인터를 이용하면 O(1)의 메모리로 풀 수 있었습니다.
2칸씩 이동하는 포인터가 1칸씩 이동하는 포인터가 만날 수 있다면, 사이클이 있는 것입니다.
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};
