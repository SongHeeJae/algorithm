#include <iostream>
#include <stack>
using namespace std;

int n, h;
long long int ans = 0;
stack<int> stk;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &h);
        while (!stk.empty() && stk.top() <= h) {
            stk.pop();
        }
        ans += stk.size();
        stk.push(h);
    }
    printf("%lld", ans);
}

/*
스택에 h를 넣어주면서 스택의 탑이 h 이하라면 pop해줍니다. (h를 확인할 수 없는 빌딩들을 제외) 
스택에 담긴 개수는, 현재 높이의 옥상을 확인할 수 있는 관리인의 수입니다. 
*/