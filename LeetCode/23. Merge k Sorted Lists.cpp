/*
lists[i][j] 값의 범위가 크지 않아서, 각 값을 카운트하여 풀 수 있었습니다.
lists의 모든 값들을 탐색하며 각 값의 개수를 저장해주고, 가장 작은 수 부터 탐색하여 병합된 정렬 리스트를 만들어줍니다.
*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int cnt[20001] = {0};
        for(ListNode* cur : lists) {
            while(cur) {
                cnt[cur->val + 10000]++;
                cur = cur->next;
            }
        }

        ListNode* head = new ListNode();
        ListNode* prv = head;
        for(int i=0; i<=20000; i++) {
            while(cnt[i]--) {
                prv->next = new ListNode(i - 10000);
                prv = prv->next;
            }
        }

        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
};


/*
추가 메모리 공간을 사용할 필요 없이, lists가 모두 병합될 때 까지 계속 순회하며, 가장 작은 값을 가지는 리스트부터 병합시켜줄 수도 있습니다.
*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode();
        ListNode* prv = head;

        while(true) {
            int minVal = INT_MAX;
            int mergedIdx = -1;
            for(int i=0; i<lists.size(); i++) {
                if(lists[i] && lists[i]->val < minVal) {
                    minVal = lists[i]->val;
                    mergedIdx = i;
                }
            }

            if(mergedIdx == -1) break;
            prv->next = new ListNode(lists[mergedIdx]->val);
            lists[mergedIdx] = lists[mergedIdx]->next;
            prv = prv->next;
        }

        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
};



/*
다음과 같이 모든 lists의 값들을 저장 및 재정렬하여 리스트를 병합할 수도 있습니다.
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> values;
        for(ListNode* cur : lists) {
            while(cur) {
                values.push_back(cur->val);
                cur = cur->next;
            }
        }

        sort(values.begin(), values.end());

        ListNode* head = new ListNode();
        ListNode* prv = head;

        for(int val : values) {
            prv->next = new ListNode(val);
            prv = prv->next;
        }

        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
};
