class Solution {
public:
    const int INF = 2000000000;
    
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int v1 = tops[0];
        int v2 = bottoms[0];
        int c[4] = { 0, 1, 1, 0 }; // top == v1, top == v2, bottom == v1, bottom == v2
        for(int i=1; i<tops.size(); i++){
            check(tops[i], bottoms[i], v1, c[0]);
            check(bottoms[i], tops[i], v1, c[1]);
            check(tops[i], bottoms[i], v2, c[2]);
            check(bottoms[i], tops[i], v2, c[3]);
        }
        int ans = min({c[0], c[1], c[2], c[3]});
        return ans >= INF ? -1 : ans;
    }
    
    void check(int cur1, int cur2, int v, int &c) {
        if(cur1 != v) {
            if(cur2 == v) c++;
            else c = INF;
        }
    }
};

/*
tops 또는 bottoms를 모두 동일하게 하려면, 기준이 되는 i번째 숫자 2개를 정해야합니다.
이를 이용하여 tops 또는 bottoms가 모두 동일한 값을 가질 수 있는 4가지 상황에서 최소 스왑 횟수를 구해주면 됩니다.

첫번째를 기준으로 한다면, tops[0] 또는 bottoms[0]으로 모든 수를 동일하게 만들 수 있습니다.
- tops의 모든 수를 tops[0]으로 만드는 경우
- tops의 모든 수를 bottoms[0]으로 만드는 경우
- bottoms의 모든 수를 tops[0]으로 만드는 경우
- bottoms의 모든 수를 bottoms[0]으로 만드는 경우
위 네 가지 상황에 대해 최소 스왑 횟수를 구해주면 됩니다.
*/