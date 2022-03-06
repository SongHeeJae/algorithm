class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || s.size() <= numRows) return s;
        
        string result;
        result.resize(s.size());
        
        int start = numRows * 2 - 2;
        int idx = 0, row = 0, flip = 0;
        int p[2] = {start, start};
        
        int i = 0;
        while(row < numRows) {
            while(idx < s.size()) {
                result[i++] = s[idx];
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
        result.resize(s.size());
        
        int start = numRows * 2 - 2;
        int idx = 0, row = 0, flip = 0;
        int p[2] = {start, start};
        
        for(int i = 0; i<s.size(); i++) {
            result[i] = s[idx];
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
*/