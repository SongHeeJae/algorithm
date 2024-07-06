/*
0이 나올 때까지 구했던 합으로 새로운 노드를 만들어서 연결해줍니다.
*/

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        ListNode *cur = head->next, *res = new ListNode();
        ListNode *resCur = res;
        while(cur) {
            sum += cur->val;
            if(cur->val == 0) {
                resCur->next = new ListNode(sum);
                resCur = resCur->next;
                sum = 0;
            }
            cur = cur->next;
        }
        return res->next;
    }
};

/*
기존 리스트에 머지하는 방식으로, 추가 공간 없이 구할 수도 있습니다.
머지된 리스트를 관리하는 slow 포인터와 기존 리스트를 순회하는 fast 포인터를 둡니다.
fast 포인터가 0을 방문할 때 까지 slow 포인터에 값을 더해줍니다.
*/

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(true) {
            slow->val += fast->val;
            fast = fast->next;
            if(!fast->next) break;
            if (fast->val == 0) {
                slow = slow->next;
                slow->val = 0;
            }
        }
        slow->next = NULL;
        return head;
    }
};


