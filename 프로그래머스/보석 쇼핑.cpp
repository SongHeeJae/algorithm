#include <string>
#include <vector>
#include <set>
#include <map>
#define INF 987654321
using namespace std;

vector<int> solution(vector<string> gems) {
    set<string> types;
    map<string, int> temp;
    vector<int> answer(2);
    answer[0] = INF;
    answer[1] = INF*2;
    int start = 0;
    for(auto g : gems) types.insert(g);
    for(int i=0; i<gems.size(); i++) {
        auto find = temp.find(gems[i]);
        if(find != temp.end()) find->second++;
        else temp.insert({gems[i], 1});
        if(types.size() == temp.size()) {
            while(start < gems.size()) {
                string startGem = gems[start];
                auto f = temp.find(startGem);
                if(f != temp.end() && f->second >= 2) {
                    f->second--;
                    start++;
                } else break;
            }
            if(i - start < answer[1] - answer[0]) {
                answer[0] = start + 1;
                answer[1] = i + 1;
            }
        }
    }
    return answer;
}

/*
다음 예시로 문제 푼 과정을 보이겠습니다.

gems = ["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]
중복 없는 보석들의 집합은 ["DIA", "RUBY", "EMERALD", "SAPPHIRE"] 으로 4개입니다.
gems를 탐색하며 각 보석들의 개수를 저장하는 map을 두겠습니다.
또한, 보석 범위의 시작 지점을 기억하는 start = 0 변수를 두고,
answer[0] = INF, answer[1] = INF*2로 초기화해서 정답은 최대의 범위를 가지게 해두겠습니다.

gems[0] -> [{"DIA", 1}] - map.size() == 1
gems[1] -> [{"DIA", 1}, {"RUBY", 1}] - map.size() == 2
gems[2] -> [{"DIA", 1}, {"RUBY", 2}] - map.size() == 2
gems[3] -> [{"DIA", 2}, {"RUBY", 2}] - map.size() == 2
gems[4] -> [{"DIA", 3}, {"RUBY", 2}] - map.size() == 2
gems[5] -> [{"DIA", 3}, {"RUBY", 2}, {"EMERALD", 1}] - map.size() == 3
gems[6] -> [{"DIA", 3}, {"RUBY", 2}, {"EMERALD", 1}, {"SAPPHIRE", 1}] - map.size() == 4

지금 이 지점에서 모든 보석을 수집하였습니다.

현재 보석을 담은 인덱스는 0~6 입니다.
이번에는 모든 보석이 담긴 상태를 유지하면서, 왼쪽 범위를 좁힐 수 있는 만큼 좁혀나가보겠습니다.

0~6 -> [{"DIA", 3}, {"RUBY", 2}, {"EMERALD", 1}, {"SAPPHIRE", 1}] - map.size() == 4
  현재 상태는 위와 같습니다. 0번 인덱스를 제외해보겠습니다.

1~6 -> [{"DIA", 2}, {"RUBY", 1}, {"EMERALD", 1}, {"SAPPHIRE", 1}] - map.size() == 4
  현재 상태는 위와 같습니다. 1번 인덱스의 보석을 제외해보겠습니다.

2~6 -> [{"DIA", 2}, {"RUBY", 0}, {"EMERALD", 1}, {"SAPPHIRE", 1}] - map.size() == 3
  현재 상태는 위와 같습니다. "RUBY"가 0으로 되면서 제거하면, map.size() == 3으로 바뀌네요. 따라서 2번 인덱스의 보석을 제외하면 안됩니다.

따라서 gems[6]까지 확인했을 때, 2~6까지가 모든 보석을 담을 수 있는 최소 범위이고, start = 2로 업데이트해줍니다.

즉, 현재 지점에서 범위 값은 i - start == 6 - 2 == 4가 됩니다.

answer[1] - answer[0] = INF 입니다.
INF > 4 이므로, answer[0] = start, answer[1] = i로 값을 바꿔줍니다.

현재 6번 인덱스까지 검사했을 때, 2~6번 범위에 저장된 보석입니다.
gems[6] -> [{"DIA", 2}, {"RUBY", 1}, {"EMERALD", 1}, {"SAPPHIRE", 1}] - map.size() == 4

​
이제 이어서 gems[7]을 진행하겠습니다.
gems[7] -> [{"DIA", 3}, {"RUBY", 1}, {"EMERALD", 1}, {"SAPPHIRE", 1}] - map.size() == 4
map.size() == 4이지만, start 지점인 2번 인덱스에 "RUBY"가 이미 담겨있어서 이것을 제외할 수는 없습니다.
*/