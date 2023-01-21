/*
문자열 s를 탐색하면서, ip 범위의 숫자를 버퍼에 담아줍니다.
버퍼의 값이 유효하다면, '.'으로 분리될 때와 분리되지 않을 때의 경로를 모두 탐색해줍니다.
사용할 수 있는 3개의 '.'을 모두 소모했다면, 남은 문자열의 수가 ip 범위인지 판별해주고, 결과 vector에 저장해줍니다.
*/

class Solution {
public:
    vector<string> res;
    string ipBuf = "";
    string buf = "";

    const int MIN_VAL = 0;
    const int MAX_VAL = 255;

    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, 3);
        return res;
    }

    void dfs(string& s, int idx, int cnt) {
        if(idx == s.size()) return;
        

        if(cnt == 0) {
            string last = s.substr(idx);
            if(isValid(last)) res.push_back(ipBuf + last);
            return;
        }

        buf.push_back(s[idx]);

        if(isValid(buf)) {
            // add dot
            string tempBuf = buf;
            string tempIpBuf = ipBuf;
            ipBuf += buf + ".";
            buf = "";
            dfs(s, idx + 1, cnt - 1);
            buf = tempBuf;
            ipBuf = tempIpBuf;
            
            // not add dot
            dfs(s, idx + 1, cnt);
        }

        buf.pop_back();

    }

    bool isValid(string& str) {
        if(str.size() == 0) return false;
        if(str.size() > 1 && str[0] == '0') return false;
        if(str.size() > 3) return false;
        int val = stoi(str);
        return MIN_VAL <= val && val <= MAX_VAL;
    }
};
