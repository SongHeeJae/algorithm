/*
n의 범위가 크지 않아서 백트래킹을 이용하여 풀었습니다.
*/

class Solution {
public:
    set<string> numSet;
    string res = "";

    string findDifferentBinaryString(vector<string>& nums) {
        numSet.insert(nums.begin(), nums.end());
        findDifferentBinaryString();
        return res;
    }
private:
    bool findDifferentBinaryString() {
        if(res.size() == numSet.size()) {
            return numSet.find(res) == numSet.end();
        }
        return findDifferentBinaryString('1') || findDifferentBinaryString('0');
    }

    bool findDifferentBinaryString(char c) {
        res.push_back(c);
        if(findDifferentBinaryString()) return true;
        res.pop_back();
        return false;
    }
};


/*
반복문을 이용하여 풀 수도 있었습니다.
nums[i][i]와 다른 비트를 사용해주면, nums에 없는 문자열을 만들어낼 수 있습니다.
*/

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res = "";
        for(int i=0; i<nums.size(); i++) {
            res.push_back(nums[i][i] == '1' ? '0' : '1');
        }
        return res;
    }
};
