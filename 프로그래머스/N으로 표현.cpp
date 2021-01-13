#include <string>
#include <vector>
using namespace std;

int cal(int a, int b, int t) {
    if(t == 0) return a + b;
    else if(t == 1) return a - b;
    else if(t == 2) return a * b;
    else {
        if(b > 0) return a / b;
    }
    return -1;
}

int solution(int N, int number) {
    if(N==number) return 1;
    vector<int> dp[8];
    dp[0].push_back(N);
    for(int i=1; i<8; i++) {
        int val = dp[i-1][0]*10 + N;
        if(val == number) return i+1;
        dp[i].push_back(val);
    }
    
    for(int i=1; i<8; i++)
        for(int j=0; j<=i-1; j++)
            for(int k=0; k<dp[j].size(); k++)
                for(int l=0; l<dp[i-1-j].size(); l++)
                    for(int m=0; m<4; m++) {
                        int val;
                        if((val = cal(dp[j][k], dp[i-1-j][l], m)) == number) return i+1;
                        if(val != -1) dp[i].push_back(val);
                    }

    return -1;
}