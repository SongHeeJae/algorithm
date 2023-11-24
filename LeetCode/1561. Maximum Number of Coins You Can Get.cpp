/*
가장 적은 pile 1개 + 가장 많은 pile 2개를 선택하고,
가장 많은 pile은 앨리스,
그 다음으로 많은 pile은 내가,
가장 적은 pile은 밥이 가져가면 됩니다.
piles 배열을 정렬해서 나의 몫을 모두 더해줍니다.
*/

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater<>());
        int res = 0;
        int n = piles.size() / 3;
        for(int i=0; i<n; i++) {
            res += piles[i * 2 + 1];
        }
        return res;
    }
};

/*
위와 동일한 방법으로 카운트 정렬을 이용하면 선형 시간에 결과를 구할 수 있습니다.
*/

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int cnt[10001] = {0};
        for(int p : piles) cnt[p]++;

        int n = piles.size() / 3, idx = 10000, res = 0;
        while(n--) {
            while(cnt[idx] <= 0) idx--;
            cnt[idx]--;
            while(cnt[idx] <= 0) idx--;
            cnt[idx]--;
            res += idx;
        }
        return res;
    }
};
