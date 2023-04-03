/*
투포인터를 이용하여 풀었습니다.
people을 오름차순으로 정렬하고,
두 사람을 하나의 보트에 태울 수 있는 경우는 양측 포인터를,
그렇지 않은 경우에는 무거운 사람을 태우도록 우측 포인터를 좁혀줍니다.
*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size() - 1, cnt = 0;
        while(l < r) {
            if(people[l] + people[r] <= limit) l++, r--;
            else r--;
            cnt++;
        }
        return cnt;
    }
};
