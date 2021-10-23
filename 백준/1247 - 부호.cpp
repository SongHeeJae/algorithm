#include <iostream>
using namespace std;

typedef long long int ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 3; i++) {
        ll s = 0, a;
        int n, cnt = 0;
        cin >> n;
        while (n--) {
            cin >> a;
            ll prv = s;
            s += a;
            if (a > 0 && prv > 0 && s < 0) cnt++;
            if (a < 0 && prv < 0 && s > 0) cnt--;
        }
        if (cnt == 0) {
            if (s == 0) cout << 0 << '\n';
            else cout << (s > 0 ? '+' : '-') << '\n';
        }
        else {
            cout << (cnt > 0 ? '+' : '-') << '\n';
        }
    }
}

/*
입력된 수가 양수이고, 입력된 양수를 더하기 전의 수도 양수인데, 더하고 난 후의 수가 음수가 된다면 오버플로가 발생한 것입니다.

입력된 수가 음수이고, 입력된 음수를 더하기 전의 수도 음수인데, 더하고 난 후의 수가 양수가 된다면 언더플로가 발생한 것입니다.

오버플로가 난 횟수와 언더플로가 난 횟수를 기억해줍니다.

(오버플로 횟수 - 언더플로 횟수) == 0 이라면, 현재 저장된 합으로 판별해줍니다.

그게 아니라면, 오버플로 횟수가 더 많으면 양수, 언더플로 횟수가 더 많으면 음수가 됩니다.
*/