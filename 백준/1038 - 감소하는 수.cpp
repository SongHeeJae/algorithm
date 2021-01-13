#include <iostream>
#include <cmath>
using namespace std;

int n, i = 1, f, j, p, jj, c = 0;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;

    if (n > 1022) printf("-1");
    else if (n == 1022) printf("9876543210");
    else if (n == 1021) printf("987654321");
    else if (n == 0) printf("0");
    else {
        while (1) {
            f = 1;
            for (j = i / 10, p = i % 10; j != 0; j /= 10, f++) {
                jj = j % 10;
                if (jj <= p) break;
                p = jj;
            }
            if (j == 0) {
                c++;
                if (c == n) {
                    printf("%d", i);
                    break;
                }
            }
            if (j != 0) {
                int t = pow(10, f);
                i = (i + t) / t * t;
            }
            else i++;
        }
    }
}