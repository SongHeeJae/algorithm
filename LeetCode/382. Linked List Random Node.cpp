/*
리스트 요소를 vector에 저장해주고, vector에서 랜덤한 요소의 값을 반환해줍니다.
*/

class Solution {
public:
    vector<int> arr;
    Solution(ListNode* head) {
        while(head) {
            arr.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};
