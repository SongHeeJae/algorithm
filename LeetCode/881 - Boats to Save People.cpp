class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        stack<int> stk;
        int cnt = 0;

        sort(people.begin(), people.end());
        
        for(int i=people.size() - 1; i>=0; i--) {
            if(!stk.empty() && stk.top() >= people[i]) {
                stk.pop();
            } else {
                int r = limit - people[i];
                if(r > 0) stk.push(r);
                cnt++;
            }
        }
        return cnt;
    }
};

/*
스택을 이용해서 풀었습니다.
내림차순으로 정렬하고, 가장 무거운 사람부터 보트에 태워줍니다.
보트에 한 사람을 태우고 남은 무게는 스택에 넣어줍니다.
즉, 스택의 top에는 가장 크게 남은 무게입니다.
점차 가벼운 사람들을 태우면서, 스택에 담긴 무게(보트)로도 충분한지 확인해줍니다.



투포인터를 이용해서 풀 수도 있었습니다.
오름차순으로 정렬했을 때,
두 인원의 합이 limit보다 작거나 같다면, 두 명 모두 한 대의 보트에 태우고,
두 인원의 합이 limit보다 크다면, 무거운 사람 한 명만 한 대의 보트에 태웁니다.
*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size() - 1;
        while(l <= r) {
            if(people[l] + people[r] <= limit) l++;
            r--;
        }
        return people.size() - r - 1;
    }
};