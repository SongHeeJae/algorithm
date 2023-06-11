/*
해시 테이블과 트리를 이용하여 풀 수 있었습니다.
각 인덱스마다 snap_id에 대한 값을 정렬하여 저장해줍니다.
snap_id에 대한 upper bound 수행 결과의 이전 snap_id를 검사해주면, 가장 최신 snap_id의 값을 구해올 수 있습니다. 
*/

class SnapshotArray {
public:
    vector<map<int, int>> snapshot; // {index, {snap_id, val}}
    int id = 0;
    
    SnapshotArray(int length) {
        snapshot.resize(length);
        for(int i=0; i<length; i++) snapshot[i][id] = 0;
    }
    
    void set(int index, int val) {
        snapshot[index][id] = val;
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        auto entry = snapshot[index].upper_bound(snap_id);
        return prev(entry)->second;
    }
};
