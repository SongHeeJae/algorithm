/*
ladder는 어떤 높이 차이든 사용할 수 있고, brick은 h[i + 1] - h[i] 이상의 개수가 남아있어야합니다.
heights를 순회하며 높이 차이가 0을 초과하면 최소 힙에 삽입해줍니다.
힙의 크기가 ladder보다 작거나 같으면, ladder를 모두 사용하면 이동할 수 있습니다.
힙의 크기가 ladder보다 커지면, 가장 작은 높이 차이에 brick을 사용해줍니다.
모든 brick을 사용하면, 더 이상 다음 건물로 이동할 수 없습니다.
*/

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        for(int i=1; i<heights.size(); i++) {
            int diff = heights[i] - heights[i - 1];
            if (diff <= 0) continue;
            pq.push(-diff);
            if(pq.size() > ladders) bricks += pq.top(), pq.pop();
            if(bricks < 0) return i - 1;
        }
        return heights.size() - 1;
    }
};


