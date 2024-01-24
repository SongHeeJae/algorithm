/*
중복 문자 여부를 판별하기 위해 비트 연산을 활용하였습니다.
문자열을 연결하지 않는 경우, 중복 문자가 없다면 문자열을 연결하는 경우를 모두 확인해줍니다.
*/

class Solution {
public:
    int myFlag = 0;
    int maxLength(vector<string>& arr) {
        return maxLength(arr, 0);
    }

    int maxLength(vector<string>& arr, int idx) {
        if(arr.size() == idx) {
            return count(myFlag);
        }

        int res = maxLength(arr, idx + 1);
        if(canConcatenate(myFlag, arr[idx])) {
            check(myFlag, arr[idx]);
            res = max(res, maxLength(arr, idx + 1));
            uncheck(myFlag, arr[idx]);
        }
        return res;
    }

private:
    bool canConcatenate(int myFlag, string& str) {
        return !isChecked(myFlag, str) && !hasDuplicated(str);
    }

    int count(int flag) {
        int c = 0;
        for(int i=0; i<26; i++) {
            if((flag >> i) & 1) c++;
        }
        return c;
    }

    void check(int& flag, string& str) {
        for(char c : str) check(flag, c);
    }

    void check(int& flag, char c) {
        flag |= (1 << (c - 'a'));
    }

    void uncheck(int& flag, string& str) {
        for(char c : str) uncheck(flag, c);
    }

    void uncheck(int& flag, char c) {
        flag ^= (1 << (c - 'a'));
    }

    bool isChecked(int flag, string& str) {
        for(char c : str)
            if(isChecked(flag, c)) return true;
        return false;
    }

    bool isChecked(int flag, char c) {
        return (flag >> (c - 'a')) & 1;
    }

    bool hasDuplicated(string& str) {
        int flag = 0;
        for(char c : str) {
            if(isChecked(flag, c)) return true;
            check(flag, c);
        }
        return false;
    }
};
