#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    int cur_weight = 0; // 다리에 올라간 무게
    int idx = 0; // 건너고 있는 트럭까지의 인덱스 번호
    int f_idx = 0; // 건너고 난 트럭 이후의 시작 인덱스 번호
    vector<int> limit(truck_weights.size(), bridge_length);
    while(idx < truck_weights.size()) {
        for(int i=f_idx; i<idx; i++) limit[i]--; // 다리 위에 올라가있는 트럭의 남은 거리 업데이트
        if(limit[f_idx] <= 0) // 다 건넜으면 업데이트
            cur_weight -= truck_weights[f_idx++];
        if(cur_weight + truck_weights[idx] <= weight) // 더 건널 수 있는 트럭이 있으면
            cur_weight += truck_weights[idx++];
        answer++;
    }
    return answer + bridge_length - 1;
}