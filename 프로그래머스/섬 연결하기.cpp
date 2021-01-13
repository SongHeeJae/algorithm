#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> d;

bool compare(vector<int>& a, vector<int>& b) {
    return a[2]<b[2];
}

int getParent(int x) {
    if(d[x] == x) return x;
    return d[x] = getParent(d[x]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    d.resize(n);
    for(int i=0; i<n;i++) {
        d[i] = i;
    }
    sort(costs.begin(), costs.end(), compare); // 정렬
    for(int i=0; i<costs.size(); i++) {
        int cur1 = getParent(costs[i][0]);
        int cur2 = getParent(costs[i][1]);
        int cost = costs[i][2];
        if(cur1 != cur2) {
            if(cur1 < cur2) d[cur2] = cur1;
            else d[cur1] = cur2;
            answer += cost;
        }
    }
    return answer;
}