#include <iostream>
using namespace std;
int n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    if (n == 1) {
        cout << "1\n1 1";
        return 0;
    }
    cout << n * 2 - 2 << "\n";
    cout << 1 << " " << 1 << "\n";
    cout << 1 << " " << n << "\n";
    for (int i = 2; i < n; i++) {
        cout << 1 << " " << i << "\n";
        cout << n << " " << i << "\n";
    }
}

/*
첫 행의 모든 칸, 마지막 행의 처음과 끝을 제외한 모든 칸에 비숍을 배치해주었습니다.
N이 1인 경우에만 별도로 처리해주었습니다.
*/