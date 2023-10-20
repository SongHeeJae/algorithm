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


/*
풀고 보니, 예전에 풀었던 문제였습니다.
nestedList를 미리 flattenedList로 변환해두었습니다.
*/

class NestedIterator {
public:
    vector<int> flattenedList;
    int cur = 0;

    NestedIterator(vector<NestedInteger> &nestedList) {
        initFlattenedList(nestedList);
    }
    
    int next() {
        return flattenedList[cur++];
    }
    
    bool hasNext() {
        return cur < flattenedList.size();
    }
private:
    void initFlattenedList(vector<NestedInteger> &nestedList) {
        for(NestedInteger& i : nestedList) {
            if(i.isInteger()) {
                flattenedList.push_back(i.getInteger());
            } else {
                initFlattenedList(i.getList());
            }
        }
    }
};


/*
이번에는 스택을 이용하여 풀었습니다.
중첩 구조를 스택을 이용하여 기억해주는 것입니다.
스택에 쌓인 NestedInteger가 중첩된 빈 리스트라면, 제거하는 작업도 필요했습니다.
*/

class NestedIterator {
public:
    stack<NestedInteger> stk;
 
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i=nestedList.size() - 1; i>=0; i--) {
            stk.push(nestedList[i]);
        }
    }
    
    int next() {
        NestedInteger ni = stk.top(); stk.pop();
        if(ni.isInteger()) {
            return ni.getInteger();
        } else {
            vector<NestedInteger>& nestedList = ni.getList();
            for(int i=nestedList.size() - 1; i >= 0; i--) {
                stk.push(nestedList[i]);
            }
            return next();
        }
    }
    
    bool hasNext() {
        clearEmpty();
        return !stk.empty();
    }

private:
    void clearEmpty() {
        while(!stk.empty() && !stk.top().isInteger() && isEmptyList(stk.top())) {
            stk.pop();
        }
    }

    bool isEmptyList(NestedInteger& ni) {
        if(ni.isInteger()) return false;
        vector<NestedInteger>& nestedList = ni.getList();
        if(nestedList.size() == 0) return true;
        bool res = true;
        for(NestedInteger& ni : nestedList) {
            res &= isEmptyList(ni);
            if(!res) return res;
        }
        return res;
    }
};


/*
위 코드를 조금 수정하면, 빈 리스트가 아닐 때에만 스택에 쌓는 방법도 있었습니다.
*/

class NestedIterator {
public:
    stack<NestedInteger> stk;
 
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i=nestedList.size() - 1; i>=0; i--) {
            if(!isEmptyList(nestedList[i])) {
                stk.push(nestedList[i]);
            }
        }
    }
    
    int next() {
        NestedInteger ni = stk.top(); stk.pop();
        if(ni.isInteger()) {
            return ni.getInteger();
        } else {
            vector<NestedInteger>& nestedList = ni.getList();
            for(int i=nestedList.size() - 1; i >= 0; i--) {
                if(!isEmptyList(nestedList[i])) {
                    stk.push(nestedList[i]);
                }
            }
            return next();
        }
    }
    
    bool hasNext() {
        return !stk.empty();
    }

private:
    bool isEmptyList(NestedInteger& ni) {
        if(ni.isInteger()) return false;
        vector<NestedInteger>& nestedList = ni.getList();
        if(nestedList.size() == 0) return true;
        bool res = true;
        for(NestedInteger& ni : nestedList) {
            res &= isEmptyList(ni);
            if(!res) return res;
        }
        return res;
    }
};
