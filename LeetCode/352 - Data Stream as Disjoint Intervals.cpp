/*
Disjoint Intervals가 무엇을 말하는건지 헷갈렸는데, 1만큼 차이나는 것을 병합해주면 되나봅니다.
정렬된 자료구조인 set에 value를 모두 저장해줍니다.
getIntervals()가 호출될 때마다, 정렬 상태로 저장된 set에서 1만큼 차이나는 데이터들을 병합해서 반환해주었습니다.
*/

class SummaryRanges {
private:
    set<int> values;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        values.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        if(values.empty())
            return {};

        vector<vector<int>> res;
        int s = *values.begin();
        int e = *values.begin();

        for(int value : values) {
            if(s == value) continue;
            if(value == e + 1) {
                e = value;
            } else {
                res.push_back({s, e});
                s = e = value;
            }
        }
        res.push_back({s, e});

        return res;
    }
};
