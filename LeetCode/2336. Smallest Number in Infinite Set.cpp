/*
제거되었다가 다시 추가된 값은 set에 저장해주고, 이를 중복이 방지되는 힙으로 사용합니다.
pop 연산은 다음과 같이 수행됩니다.
set에 저장된 값이 있다면, 가장 작은 값을 꺼내주고, set에서는 제거해줍니다.
set에 저장된 값이 없다면, 1부터 값을 제거해주고, 현재까지 제거된 가장 작은 값을 기억해줍니다.
새로운 값이 현재까지 제거된 가장 작은 값보다 작다면, 해당 값은 이미 제거되었다가 추가된다는 것을 의미하므로 set에 넣어줍니다.
*/

class SmallestInfiniteSet {
public:
    set<int> s;
    int smallest = 1;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(s.empty()) {
            return smallest++;
        } else {
            int val = *s.begin();
            s.erase(s.begin());
            return val;
        }
        
    }
    
    void addBack(int num) {
        if(smallest > num) s.insert(num);
    }
};
