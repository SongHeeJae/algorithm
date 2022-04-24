/*
비트 연산을 이용하여 풀었습니다.
수의 범위는 0이상 1000000이하 이므로, 1000001개의 수를 표시할 수 있어야합니다.
32비트 정수 하나에는 32개의 수가 나타났음을 표시할 수 있습니다.
따라서, 31251개의 정수 배열로 HashSet을 구현할 수 있었습니다.
*/

class MyHashSet {
public:
    int val[31251] = { 0 };
    
    MyHashSet() { }
    
    void add(int key) {;
        val[key / 32] |= 1 << (key % 32);
    }
    
    void remove(int key) {
        val[key / 32] &= ~(1 << key % 32);
    }
    
    bool contains(int key) {
        return val[key / 32] & (1 << key % 32);
    }
};

/*
고정된 범위를 가지고 있고 수의 분포가 고르다(위 문제에서 이건 모르지만)면, 위 방법이 크게 문제는 없을 것입니다.
그렇지 않다면, 다른 방법을 고민해봐야할 것입니다.
*/