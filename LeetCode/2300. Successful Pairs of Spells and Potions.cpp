/*
lower bound를 이용하여 풀 수 있습니다.
potions를 오름차순으로 정렬하고, spell * potion이 success 이상인 최소 인덱스를 찾아줍니다.
해당 인덱스 이상의 모든 potion과 spell의 쌍은 successful pair가 됩니다.
*/

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> pairs;
        sort(potions.begin(), potions.end());
        for(int spell : spells) {
            pairs.push_back(potions.size() - lowerBound(potions, spell, success));
        }
        return pairs;
    }

    int lowerBound(vector<int>& potions, long long spell, long long success) {
        int l = 0, r = potions.size();
        while(l < r) {
            int m = (l + r) / 2;
            spell * potions[m] >= success ? r = m : l = m + 1;
        }
        return r;
    }
};
