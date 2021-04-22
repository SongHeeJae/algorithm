#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> foods;
bool visit[10] = {false};
void generateFoods(string& order, string& temp, int idx, int c, int cnt) {
    if(c == cnt) {
        if(foods[temp]) foods[temp]++;
        else foods[temp] = 1;
        return;
    }
    for(int i=idx; i<order.size(); i++) {
        if(visit[i]) continue;
        visit[i] = true;
        temp.push_back(order[i]);
        generateFoods(order, temp, i + 1, c + 1, cnt);
        temp.pop_back();
        visit[i] = false;
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> ans;
    for(int i=0; i<orders.size(); i++) sort(orders[i].begin(), orders[i].end());
    string temp = "";
    for(int i=0; i<course.size(); i++) {
        foods.clear();
        for(int j=0; j<orders.size(); j++) {
            generateFoods(orders[j], temp, 0, 0, course[i]);
        }
        int m = 0;
        for(auto it = foods.begin(); it != foods.end(); it++) {
            m = max(m, it->second);
        }
        if(m < 2) continue;
        for(auto it = foods.begin(); it != foods.end(); it++) {
            if(m == it->second)
                ans.push_back(it->first);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

/*
먼저 'XY'와 'YX'처럼 동일한 주문 조합이지만 순서 차이에 따른 문제를 해결하기 위해 orders의 각 스트링들을 정렬해줍니다.
그 후, 정렬된 orders의 각 스트링 내에서 course의 각 길이별로 뽑아낼 수 있는 모든 조합과 그 개수를 map에 기억해줍니다.
각 길이별 최대 개수가 2개 이상이라면, ans에 담아줍니다.
*/