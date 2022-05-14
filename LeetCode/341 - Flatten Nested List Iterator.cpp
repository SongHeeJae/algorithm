/*
재귀를 이용하여 1차원 배열로 초기화시켜주었습니다.
*/

class NestedIterator {
public:
    vector<int> values;
    int idx = 0;
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        init(nestedList);
    }
    
    int next() {
        return values[idx++];
    }
    
    bool hasNext() {
        return idx < values.size();
    }
    
private:
    void init(vector<NestedInteger>& nestedList) {
        for(auto& nested : nestedList) {
            if(nested.isInteger()) {
                values.push_back(nested.getInteger());
            } else {
                init(nested.getList());
            }
        }
    }
};