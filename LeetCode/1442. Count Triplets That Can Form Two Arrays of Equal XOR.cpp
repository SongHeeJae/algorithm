/*
arr의 prefix xor을 초기화해주면, prefixXor[j] ^ prefixXor[i]로 arr[i] ~ arr[j - 1]의 xor된 연산을 즉시 구할 수 있습니다.
O(N^3)의 시간으로 풀 수 있었습니다. ( N <= 300)
*/

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> prefixXor(arr.size() + 1);
        prefixXor[0] = 0;
        for(int i=1; i<=arr.size(); i++) prefixXor[i] = prefixXor[i-1] ^ arr[i - 1];

        int cnt = 0;
        for(int i=0; i<arr.size(); i++) {
            for(int j=i+1; j<arr.size(); j++) {
                for(int k=j; k<arr.size(); k++) {
                    int a = prefixXor[j] ^ prefixXor[i];
                    int b = prefixXor[k + 1] ^ prefixXor[j];
                    if(a == b) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};

/*
위 코드에서,
a == b 
prefixXor[j] ^ prefixXor[i] == prefixXor[k + 1] ^ prefixXor[j]
prefixXor[i] == prefixXor[k + 1]
가 되므로, 이를 만족하는 j의 개수를 구해줄 수 있습니다. (0 <= i < j <= k < arr.length)
O(N^2)의 시간으로 풀 수 있었습니다.
*/

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> prefixXor(arr.size() + 1);
        prefixXor[0] = 0;
        for(int i=1; i<=arr.size(); i++) prefixXor[i] = prefixXor[i-1] ^ arr[i - 1];

        int cnt = 0;
        for(int i=0; i<=arr.size(); i++) {
            for(int j=i+1; j<=arr.size(); j++) {
                if(prefixXor[i] == prefixXor[j]) {
                    cnt += j - i - 1;
                }
            }
        }
        return cnt;
    }
};
