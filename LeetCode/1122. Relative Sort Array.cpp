/*
arr2 각 요소의 인덱스를 기억해주고, 이 정보를 이용하여 arr1을 정렬해줍니다.
*/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> idx(1001, -1);
        for(int i=0; i<arr2.size(); i++) idx[arr2[i]] = i;
        sort(arr1.begin(), arr1.end(), [&](int a, int b) {
            int idx1 = idx[a];
            int idx2 = idx[b];
            if(idx1 != -1 && idx2 != -1) {
                return idx1 < idx2;
            } else if(idx1 == -1 && idx2 == -1) {
                return a < b;
            } 
            return idx1 > idx2;
        });
        return arr1;
    }
};

/*
arr1 각 요소의 개수를 구해주고, arr2의 각 요소를 순회하는 순서로 정렬해줍니다.
*/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> cnt(1001, 0), res;
        for(int i=0; i<arr1.size(); i++) cnt[arr1[i]]++;
        for(int i=0; i<arr2.size(); i++)
            while(cnt[arr2[i]]--) res.push_back(arr2[i]);
        for(int i=0; i<1001; i++)
            while(cnt[i]-- > 0) res.push_back(i);
        return res;
    }
};
