/*
방문 여부를 표시하여 사이클이 생기는지 확인할 수 있었습니다.
*/

class Solution {
public:
    unordered_set<ListNode*> visit;
    ListNode *detectCycle(ListNode *head) {
        while(head != NULL) {
            if(visit.find(head) != visit.end()) return head;
            visit.insert(head);
            head = head->next;
        }
        return NULL;
    }
};

/*
플로이드 사이클 탐지 알고리즘을 이용하면, O(n) 메모리를 사용하는 위 방식과 달리 O(1) 메모리로 해결할 수 있습니다.
slow와 fast 2개의 포인터를 두고, slow는 1칸씩, fast는 2칸씩 움직입니다.
0부터 사이클 시작 지점 사이의 거리가 a,
사이클 지작 지점에서 두 개의 포인터가 만나는 지점 사이의 거리가 b,
두 개의 포인터가 만나는 지점에서 tail 지점 사이의 거리가 c라면,
두 개의 포인터가 만나게 되었을 때의, slow 포인터가 이동한 거리는 a + b, fast 포인터가 이동한 거리는 a + b + c + b가 됩니다.
fast는 slow보다 2배의 이동 거리를 가지므로,
2 * (a + b) = a + 2 * b + c이고,
a = c가 됩니다.
즉, slow 또는 fast가 a만큼 더 움직이면, 사이클의 시작 지점에 도달하게 됩니다.
slow를 head 포인터로 돌려놓고, slow와 fast가 같아질 때 까지 순회하면, a만큼 움직이게 된 셈입니다.
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                slow = head;
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};
