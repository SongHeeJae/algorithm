/*
list1의 삭제 시작/종료 포인터를 구해서, list2를 끼워넣어줍니다.
*/

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* cur1 = list1;
        for(int i=1; i<a; i++) {
            cur1 = cur1->next;
        }

        ListNode* cur2 = cur1->next;
        cur1->next = list2;
        for(int i=0; i<=b-a; i++) {
            cur2 = cur2->next;
        }

        while(list2->next != NULL) {
            list2 = list2->next;
        }
        
        list2->next = cur2;
        return list1;
    }
};
