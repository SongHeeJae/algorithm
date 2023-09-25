/*
s와 t의 각 문자 개수를 구하고, 1개 더 많은 문자를 찾아주면 됩니다. 
*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        int alp[26] = {0};
        for(int i=0; i<s.size(); i++)
            alp[s[i] - 'a']--, alp[t[i] - 'a']++;
        alp[t.back() - 'a']++;
        
        for(int i=0; i<26;i++)
            if(alp[i]) return i + 'a';
        return 0;
    }
};


/*
합을 이용하여 구할 수도 있었습니다.
t의 모든 문자합에서 s을 모든 문자 합을 빼면, 1개 더 많은 문자를 찾을 수 있습니다.
*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum = 0;
        for(int i=0; i<s.size(); i++)
            sum += t[i] - s[i];
        sum += t.back();
        return (char)sum;
    }
};


/*
xor 연산을 이용하여 구할 수도 있었습니다.
s와 t의 모든 문자를 xor 연산해주면, 홀수번 나오는 1개 더 많은 문자를 찾을 수 있습니다.
*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        int x = 0;
        for(int i=0; i<s.size(); i++)
            x ^= s[i] ^ t[i];
        x ^= t.back();
        return (char)x;
    }
};
