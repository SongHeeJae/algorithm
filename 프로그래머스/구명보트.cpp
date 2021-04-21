#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int l = 0 , r = people.size() - 1, ans = 0;
    sort(people.begin(), people.end());
    while(l <= r) {
        if(people[l] + people[r] <= limit) l++;
        r--, ans++;
    }
    return ans;
}

/*
한 배에는 최대 2명까지 탈 수 있습니다.
먼저 사람들의 몸무게를 오름차순으로 정렬해줍니다.
맨 앞 사람과 맨 뒷 사람의 합이 limit이하라면, 보트에 두명 다 태우면됩니다.
맨 앞 사람과 맨 뒷 사람의 합이 limit초과라면, 보트에 맨 뒷사람 한명만 태웁니다.
*/