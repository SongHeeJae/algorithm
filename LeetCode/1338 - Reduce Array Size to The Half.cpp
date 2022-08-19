/*
숫자 당 개수를 구해서 정렬해준 뒤, 그 제거된 개수가 절반 이상이 되는 집합 요소의 수를 구해주었습니다.
*/

class Solution {
public:
    int cnt[100001] = {0};
    int minSetSize(vector<int>& arr) {
        for(int i=0; i<arr.size(); i++) {
            cnt[arr[i]]++;
        }
        
        int res = 0;
        int c = arr.size() / 2;
        vector<int> sorted;
        for(int i=0; i<100001; i++) {
            if(cnt[i]) sorted.push_back(cnt[i]);
        }
        sort(sorted.begin(), sorted.end());
        
        for(int i=sorted.size() - 1; i>=0; i--) {
            c -= sorted[i];
            res++;
            if(c <= 0) break;
        }
        return res;
    }
};
