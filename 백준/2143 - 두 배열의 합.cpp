#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int t, n, m, a[1000], b[1000];
long long int ans = 0, c1, c2;
vector<int> A, B;
int main() {
    scanf("%d", &t);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);

    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = i; j < n; j++) {
            c += a[j];
            A.push_back(c);
        }
    }

    for (int i = 0; i < m; i++) {
        int c = 0;
        for (int j = i; j < m; j++) {
            c += b[j];
            B.push_back(c);
        }
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (int l = 0, r = B.size() - 1; l < A.size() && r >= 0;) {
        if (A[l] + B[r] < t) l++;
        else if (A[l] + B[r] > t) r--;
        else {
            c1 = c2 = 0;
            for (int tmp = A[l]; l < A.size() && tmp == A[l]; l++, c1++);
            for (int tmp = B[r]; r >= 0 && tmp == B[r]; r--, c2++);
            ans += c1 * c2;
        }
    }

    printf("%lld", ans);
}

/*
투포인터를 활용하여 해결한 문제였습니다. 
A, B 배열에 모든 부 배열 합을 구해준 뒤, 모든 경우의 수를 구해줬습니다.
*/