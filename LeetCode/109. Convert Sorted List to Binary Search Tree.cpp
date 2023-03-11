/*
리스트의 중앙 노드가 트리의 루트가 되어야 height-balanced binary search tree를 만들 수 있습니다.
리스트를 절반씩 재귀적으로 분할하여, 리프 노드에서부터 서브 트리를 만들어나가고, 이를 상위 depth 노드의 자식 노드로 지정해주면 됩니다.
리스트의 중앙 노드를 찾는 과정은, 2개의 탐색 포인터를 이용할 수 있습니다.
리스트의 head에서부터, 1칸 및 2칸 이동하는 두 개의 포인터를 선언해줍니다.
2칸 이동하는 포인터가 리스트의 끝에 도달하였을 때, 1칸 이동하는 포인터가 리스트의 중앙 노드가 됩니다.
*/

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return convert(head, NULL);
    }

    TreeNode* convert(ListNode* start, ListNode* end) {
        if(start == end) {
            return NULL;
        }

        ListNode* slow = start;
        ListNode* fast = start;

        while(fast != end && fast->next != end) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return new TreeNode(
            slow->val, 
            convert(start, slow), 
            convert(slow->next, end)
        );
    }
};
