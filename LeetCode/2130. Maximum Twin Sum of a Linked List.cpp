/*
중간 노드까지 스택에 값을 쌓아주고, 해당 값들을 이용하여 마지막 노드까지의 twin sum을 확인해주었습니다.
*/

class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> stk;
        ListNode *slow = head, *fast = head;
        while(fast) {
            stk.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }

        int res = 0;
        while(slow) {
            res = max(res, slow->val + stk.top());
            slow = slow->next;
            stk.pop();
        }
        return res;
    }
};


/*
스택을 사용하지 않고, 리스트를 뒤집어서 풀 수도 있었습니다.
중간 노드를 찾아주고, 중간 노드부터 끝 노드까지 뒤집어줍니다.
헤드와 중간 노드부터 뒤집어진 리스트 헤드를 이용하여 twin sum을 구할 수 있습니다.
*/

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* reverse = NULL;
        while(slow) {
            swap(slow->next, reverse);
            swap(reverse ? reverse->next : reverse, slow);
        }

        int res = 0;
        while(reverse) {
            res = max(res, head->val + reverse->val);
            head = head->next;
            reverse = reverse->next;
        }
        return res;
    }
};
