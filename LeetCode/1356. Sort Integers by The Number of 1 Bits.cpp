/*
각 수의 비트 개수를 구해주고, 정렬에 활용합니다.
0 <= arr[i] <= 10^4 이므로, 14개의 비트만 검사해주면 됩니다. 
*/

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [this](const int a, const int b) {
            int aBitCount = findBitCount(a);
            int bBitCount = findBitCount(b);
            return aBitCount != bBitCount ? aBitCount < bBitCount : a < b;
        });
        return arr;
    }

private:
    int findBitCount(int n) {
        int c = 0;
        for(int i=0; i<14; i++) {
            c += n & 1;
            n >>= 1;
        }
        return c;
    }
};

/*
동일한 비트 개수를 가지는 숫자들을 그룹핑하여 정렬해줍니다.
이를 이용하여 결과를 만들어줍니다.
*/

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int, vector<int>> countToIntegers;

        for(int n : arr) {
            int bitCount = findBitCount(n);
            countToIntegers[findBitCount(n)].push_back(n);
        }

        int idx = arr.size() - 1;
        for(int i=13; i>=0; i--) {
            sort(countToIntegers[i].begin(), countToIntegers[i].end(), greater<>());
            for(int n : countToIntegers[i]) {
                arr[idx--] = n;
            }
        }

        return arr;
    }

private:
    int findBitCount(int n) {
        int c = 0;
        for(int i=0; i<14; i++) {
            c += n & 1;
            n >>= 1;
        }
        return c;
    }
};
