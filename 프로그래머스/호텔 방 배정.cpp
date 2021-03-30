#include <string>
#include <vector>
#include <map>
using namespace std;

map<long long, long long> used;

long long getEmpty(long long room) {
    auto f = used.find(room);
    if(f == used.end()) return room;
    else return f->second = getEmpty(f->second);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for(int i=0; i<room_number.size(); i++) {
        long long room = room_number[i];
        auto f = used.find(room);
        if(f != used.end()) {
            long long ret = getEmpty(room);
            used.insert({ret, getEmpty(ret+1)});
            answer.push_back(ret);
        } else {
            answer.push_back(room);
            used.insert({room, getEmpty(room+1)});
        }
    }
    return answer;
}

/*
사용되지않은 방을 선택하면, 다음으로 나오는 빈 방과 함께 기록해줍니다.

사용한 방을 선택하면, 다음으로 나오는 빈 방을 찾고, 그 방에서부터 다음으로 나오는 빈 방과 함께 기록해줍니다.

빈 방을 찾았을 때, 그 빈 방을 찾기까지 지나친 모든 방들의 빈 방도, 새로 찾은 그 빈 방으로 수정해줍니다.
*/