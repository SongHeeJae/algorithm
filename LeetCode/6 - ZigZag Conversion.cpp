class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || s.size() <= numRows) return s;
        
        string result;
        int start = numRows * 2 - 2;
        int idx = 0, row = 0, flip = 0;
        int p[2] = {start, start};
        
        for(char ch : s) {
            result.push_back(s[idx]);
            idx += p[flip];
            flip = !flip;
            if(idx >= s.size()) {
                idx = ++row;
                if(row == numRows - 1) p[0] = p[1] = start;
                else if(row == 1) p[0] -= 2, p[1] = 2;
                else p[0] -= 2, p[1] += 2;
                flip = 0;
            }
        }
        return result;
    }
};

/*
규칙을 찾아서 풀었습니다.
예를 들어 numRows=4라면,
1행은 6칸 씩,
2행은 4칸과 2칸이 번갈아가면서,
3행은 2칸과 4칸이 번갈아가면서,
4행은 6칸 씩,
기존의 문자열에서 점프하게 됩니다.

즉 numRows=n이라면,
1행은 (n * 2 - 2)칸 씩,
2행은 (n * 2 - 4)칸과 2칸이 번갈아가면서,
3행은 (n * 2 - 6)칸과 4칸이 번갈아가면서,
...
n행은 (n * 2 - 2)칸 씩,
기존의 문자열에서 점프하게 됩니다.

numRows == 1이거나 문자열의 길이가 numRows인 경우는, 주어진 문자열 s를 즉시 반환해주었습니다.
 
위 방식으로 코드를 작성하면, n의 시간복잡도와 공간복잡도로 문제를 해결할 수 있었습니다.

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || s.size() <= numRows) return s;
        
        string result;
        int start = numRows * 2 - 2;
        int idx = 0, row = 0, flip = 0;
        int p[2] = {start, start};
        while(row < numRows) {
            while(idx < s.size()) {
                result.push_back(s[idx]);
                idx += p[flip];
                flip = !flip;
            }
            idx = ++row;
            flip = 0;
            if(row == numRows - 1) p[0] = p[1] = start;
            else if(row == 1) p[0] -= 2, p[1] = 2;
            else p[0] -= 2, p[1] += 2;
        }
        return result;
    }
};
*/


/*
규칙을 파악하면 문자열을 한 번 순회하며 변환된 문자열을 구할 수 있습니다.
numRows == 1이라면, 주어진 문자열을 그대로 반환해줍니다.
0행은 다음 알파벳까지 numRows * 2 - 2번 건너뛰면 됩니다.
i행은 다음 알파벳까지 (numRows - i) * 2 - 2번, (i + 1) * 2 - 2번 번갈아가면서 건너뛰면 됩니다.
(numRows -1)행은 다음 알파벳까지 numRows * 2- 2번 건너뛰면 됩니다.
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        string result = "";
        for(int i=0; i<numRows; i++) {
            int d = (numRows - i) * 2 - 2;
            int u = (i + 1) * 2 - 2;

            if(i == 0) u = d;
            else if(i == numRows - 1) d = u;

            bool flag = true;
            for(int j = i; j < s.size(); j += flag ? d : u, flag = !flag)
                result.push_back(s[j]);
        }

        return result;
    }
};
