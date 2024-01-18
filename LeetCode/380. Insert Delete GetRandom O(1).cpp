/*
insert와 remove는 unordered 자료구조를 이용하여 O(1)에 처리해줍니다.
랜덤한 val을 O(1)에 얻기 위해 insert 시에 vector에도 val을 저장해주고, unordered_map에 각 val의 index도 저장해줍니다.
remove할 때에는, vector에서 삭제된 val에 대한 데이터와 마지막 데이터를 스왑해주고, vector와 unordered_map에서 삭제된 val에 대해 정리해줍니다.
*/

class RandomizedSet {
public:
    unordered_map<int, int> s;
    vector<int> v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        auto f = s.find(val);
        if(f != s.end()) {
            return false;
        }
        s[val] = v.size();
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        auto f = s.find(val);
        if(f == s.end()) {
            return false;
        }

        int lastIndex = v.size() - 1;
        int lastVal = v.back();
        v.pop_back();

        int removedIndex = f->second;

        v[removedIndex] = lastVal;
        s[lastVal] = removedIndex;
        s.erase(f);
        
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};
