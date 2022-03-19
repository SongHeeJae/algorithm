struct compare{
    bool operator()(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b){
        if(a.first != b.first) return a.first < b.first;
        else return a.second.first < b.second.first;
    }
};

class FreqStack {
public:
    int c = 0;
    unordered_map<int, int> cnt; // {수, 빈도수}

    // {빈도수, 삽입 순서, 수}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare> pq;
    
    FreqStack() { }
    
    void push(int val) {
        auto f = cnt.find(val);
        if(f == cnt.end()) {
            pq.push({ 1, { c++, val } });
            cnt.insert({val, 1});
        } else {
            pq.push({ ++f->second, { c++, val } });
        }
    }
    
    int pop() {
        int val = pq.top().second.second;
        cnt[val]--;
        pq.pop();
        return val;
    }
};

/*
우선순위 큐를 이용하여 {빈도수, 스택에 가까운 정도}가 가장 큰 순서를 유지해주었습니다.
로그 시간에 push와 pop을 수행할 수 있게 됩니다.
단, c는 올라가기만 하니 문제 외의 조건에선 별다른 조치를 취해야할 것입니다. 

 
다른 풀이도 살펴보니, 아래와 같이 빈도수에 따른 수 그룹을 관리하는 방법으로도 풀 수 있었습니다.
해시맵을 이용하면 상수 시간에 push, pop을 수행할 수 있게 됩니다.
*/

class FreqStack {
public:
    unordered_map<int, int> cnt; // {수, 빈도수}
    unordered_map<int, vector<int>> grp; // {빈도수, 수 그룹}
    int mxFreq = 0;

    FreqStack() { }
    
    void push(int val) {
        int freq = 1;
        auto f = cnt.find(val);
        if(f == cnt.end()) cnt.insert({val, 1});
        else freq = ++f->second;
        
        auto ff = grp.find(freq);
        if(ff != grp.end()) ff->second.push_back(val);
        else grp.insert({freq, vector<int>(1, val)});
        mxFreq = max(mxFreq, freq);
    }
    
    int pop() {
        auto f = grp.find(mxFreq);
        int val = f->second.back();
        cnt[val]--;
        f->second.pop_back();
        if(f->second.size() == 0) mxFreq--;
        return val;
    }
};