#include <string>
#include <vector>
#include <set>
using namespace std;

bool solution(vector<string> phone_book) {
    set<string> st(phone_book.begin(), phone_book.end());
    for(auto it = st.begin(); it != st.end(); it++)
        for(int i=1; i< it->size(); i++)
            if(st.find(it->substr(0, i)) != st.end()) return false; 
    return true;
}

/*
set에 모든 전화번호를 담아주고, 각 전화번호가 다른 전화번호의 접두어인지 확인해주었습니다.
*/