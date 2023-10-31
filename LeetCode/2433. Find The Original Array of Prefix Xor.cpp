/*
pref를 순회하며 arr[i - 1]까지 xor된 연산 결과를 기억해주고, 
해당 연산 결과와 pref[i]를 xor 연산하면, arr[i]를 구할 수 있습니다.
*/

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        for(int i=0, j=0; i<pref.size(); i++) {
            pref[i] = j ^ pref[i];
            j ^= pref[i];
        }
        return pref;
    }
};
