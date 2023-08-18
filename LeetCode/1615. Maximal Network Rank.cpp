/*
각 도시의 연결 여부와 도시에 연결된 길의 개수를 초기화해줍니다.
연결된 길의 개수는, 첫번째로 큰 수와 두번째로 큰 수를 maximal network rank의 후보지로 사용할 수 있습니다.
연결된 길의 개수가 첫번째로 큰 도시들, 연결된 길의 개수가 두번째로 큰 도시들의 연결 여부를 판별하여 rank를 구해줍니다.
*/

class Solution {
public:
    bool graph[100][100] = {false};
    int cnt[100] = {0};

    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        for(auto& r : roads) {
            graph[r[0]][r[1]] = graph[r[1]][r[0]] = true;
            cnt[r[0]]++;
            cnt[r[1]]++;
        }

        vector<pair<int, int>> val;
        for(int i=0; i<n; i++) {
            val.push_back({cnt[i], i});
        }
        sort(val.begin(), val.end(), greater<>());

        int limit = val[1].first;
        int res = 0;
        for(int i=0; i<val.size() && val[i].first >= limit; i++) {
            for(int j=i+1; j<val.size() && val[j].first >= limit; j++) {
                res = max(res, getRank(val[i], val[j]));
            }
        }
        return res;
    }

    int getRank(pair<int, int>& a, pair<int, int>& b) {
        return a.first + b.first - graph[a.second][b.second];
    }
};

