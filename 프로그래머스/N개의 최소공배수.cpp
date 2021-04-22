#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> arr) {
    int m = arr[0];
    for(int i=1; i<arr.size(); i++) {
        m = max(arr[i], m);
    }
    int ans = m;
    while(1) {
        int i;
        for(i=0; i<arr.size(); i++) {
            if(ans % arr[i] != 0) {
                break;
            }
        }
        if(i == arr.size()) break;
        ans += m;
    }
    return ans;
}

/*
최댓값을 누적해서 더하며 모든 수의 최소공배수를 찾아주었습니다.
*/