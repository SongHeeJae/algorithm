/*
key, value 값의 범위를 수용할만큼 배열을 선언하고, 각 수에 대한 배열 인덱스에 즉시 접근하면 됩니다.
*/

class MyHashMap {
public:
    int m[1000001];

    MyHashMap() {
        memset(m, -1, sizeof(m));
    }
    
    void put(int key, int value) {
        m[key] = value;
    }
    
    int get(int key) {
        return m[key];
    }
    
    void remove(int key) {
        m[key] = -1;
    }
};


/*
key, value 값의 범위를 모두 수용할만큼 배열을 선언하면, 메모리를 과도하게 사용할 수가 있습니다.
각 key를 적절한 크기로 파티션해주고, 같은 파티션에 저장되는 데이터에 대해서는 트리 구조로 저장해주었습니다.
적절한 해시 함수 및 크기로 각 파티션에 균일하게 분산될 수 있다면, 일반적인 상황에서는 여전히 상수 시간에 접근할 수 있게 됩니다. 
*/

class MyHashMap {
public:
    const static int HASH_SIZE = 1000;
    map<int, int> m[HASH_SIZE];

    MyHashMap() {

    }
    
    void put(int key, int value) {
        m[genHashKey(key)][key] = value;
    }
    
    int get(int key) {
        int k = genHashKey(key);
        auto f = m[k].find(key);
        if(f == m[k].end()) return -1;
        return f->second;
    }
    
    void remove(int key) {
        m[genHashKey(key)][key] = -1;
    }

private:
    int genHashKey(int key) {
        return key % HASH_SIZE;
    }
};


/*
트리 구조로 인해 같은 파티션에 충돌된 데이터에 대해 조회 속도는 빠를 수 있지만,
데이터에 따라 삽입/삭제 연산 속도가 느려지고, 트리 노드에 대한 포인터를 유지해야하기 때문에 추가적인 메모리가 요구될 수 있습니다.
대안으로 리스트를 사용하는 것도 간단하고 문제 없어보입니다.
*/

class MyHashMap {
public:
    const static int HASH_SIZE = 1000;
    list<pair<int, int>> m[HASH_SIZE];

    MyHashMap() {

    }
    
    void put(int key, int value) {
        int k = genHashKey(key);
        list<pair<int, int>>& p = m[k];
        for(auto& val : p) {
            if(val.first == key) {
                val.second = value;
                return;
            }
        }
        p.push_back({key, value});
    }
    
    int get(int key) {
        int k = genHashKey(key);
        list<pair<int, int>>& p = m[k];
        for(auto& val : p) {
            if(val.first == key) {
                return val.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int k = genHashKey(key);
        list<pair<int, int>>& p = m[k];
        for(auto it = p.begin(); it != p.end(); it++) {
            if(it->first == key) {
                p.erase(it);
                return;
            }
        }
    }

private:
    int genHashKey(int key) {
        return key % HASH_SIZE;
    }
};
