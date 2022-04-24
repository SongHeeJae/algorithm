/*
map과 저장된 개수를 이용하여 원본 url을 유지할 수 있었습니다.
*/

class Solution {
public:
    map<int, string> m;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        m[m.size()] = longUrl;
        return "http://tinyurl.com/" + to_string(m.size() - 1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int idx = shortUrl.rfind('/');
        return m[stoi(shortUrl.substr(idx + 1))];
    }
};


/*
다음과 같이 depth를 나눠서 풀이할 수도 있었습니다.
도메인까지의 영역(depth1)과 이후의 영역(depth2)을 분리해준 것입니다.
이를 통해 동일한 depth1의 중복 저장을 막아주게 됩니다.
*/

class Solution {
public:
    map<int, string> depth1;
    map<string, int> depth1Reverse;
    
    map<int, map<int, string>> depth2;
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        int idx = getDepth1LastIdx(longUrl);
        
        string depth1Url = longUrl.substr(0, idx);
        string depth2Url = longUrl.substr(idx);
        
        int depth1Idx = insertDepth1(depth1Url);
        int depth2Idx = insertDepth2(depth1Idx, depth2Url);
        
        return "http://tinyurl.com/" + to_string(depth1Idx)
            + (depth2Idx == -1 ? "" : "-" + to_string(depth2Idx));
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string path = shortUrl.substr(shortUrl.rfind('/') + 1);
        
        int idx = path.find('-');
        int depth1Idx = stoi(path.substr(0, idx));
        int depth2Idx = stoi(path.substr(idx + 1));
        return depth1[depth1Idx] + depth2[depth1Idx][depth1Idx];
    }
    
private:
    int getDepth1LastIdx(string& url) {
        int c = 0;
        for(int i=0; i<url.size(); i++)
            if(url[i] == '/' && ++c == 3) return i;
        return url.size();
    }
    
    int insertDepth1(string& url) {
        auto f = depth1Reverse.find(url);
        if(f != depth1Reverse.end()) return f->second;
        depth1[depth1Reverse.size()] = url;
        depth1Reverse[url] = depth1Reverse.size();
        return depth1Reverse.size() - 1;
    }
    
    int insertDepth2(int depth1Idx, string& url) {
        if(url.size() == 0) return -1;
        
        if(depth2.find(depth1Idx) == depth2.end())
            depth2[depth1Idx] = map<int, string>();
        
        int depth2Idx = depth2[depth1Idx].size();
        depth2[depth1Idx][depth2Idx] = url;
        
        return depth2Idx;
    }
};

/*
depth2도 중복 저장을 막아주고 싶다면, 역방향 map을 만들어주면 될 것입니다. 

 
순차적인 숫자로 올리는 것은 몇 가지 문제가 있습니다.
저장된 url의 개수를 유추할 수 있고, map의 key로 사용되는 자료형의 범위를 벗어나게 되면 에러가 발생할 수 있습니다.
문자를 key로 이용하여 다음과 같이 풀이할 수도 있었습니다.
역방향을 이용하여 중복 url의 저장도 방지해주었습니다.
*/

class Solution {
public:
    map<string, string> encToDec;
    map<string, string> decToEnc;
    
    string characters = "abcdeafghijklmnopABCDEFGHIJKLMNOP0123456789";
    
    Solution() {
        srand((unsigned int)time(NULL));
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(decToEnc.find(longUrl) != decToEnc.end())
            return "http://tinyurl.com/" + decToEnc[longUrl];
        
        while(1) {
            string encodedUrl = "";
            for(int i=0; i<6; i++) {
                encodedUrl.push_back(characters[rand() % characters.size()]);
            }
            if(encToDec.find(encodedUrl) == encToDec.end()) {
                decToEnc[longUrl] = encodedUrl;
                encToDec[encodedUrl] = longUrl;
                break;
            }
        }
        return "http://tinyurl.com/" + decToEnc[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return encToDec[shortUrl.substr(shortUrl.rfind('/') + 1)];
    }
};

/*
위 경우도 depth를 분리하면 저장 공간을 더욱 효율적으로 사용할 수 있을 것입니다.

 

depth를 분리하는 것은 이전의 방식에서 해봤으니 생략하고, 다른 측면에서 조금 더 개선해보겠습니다.
고정된 글자 수로 인코딩하기 때문에,
만들 수 있는 모든 경우의 수를 다 사용하게 되면 충돌이 끊임없이 발생해서 무한 루프에 빠질 위험이 있습니다.
재시도를 몇 번 수행할지 지정해두고, 이를 초과한다면 글자 수를 유동적으로 증가시켜주는 것입니다. 
*/


class Solution {
public:
    map<string, string> encToDec;
    map<string, string> decToEnc;
    
    string characters = "abcdeafghijklmnopABCDEFGHIJKLMNOP0123456789";
    
    int RETRY = 3;
    int SIZE = 6;
    
    Solution() {
        srand((unsigned int)time(NULL));
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(decToEnc.find(longUrl) != decToEnc.end())
            return "http://tinyurl.com/" + decToEnc[longUrl];
        
        int count = 0;
        while(1) {
            string encodedUrl = "";
            for(int i=0; i<SIZE; i++) {
                encodedUrl.push_back(characters[rand() % characters.size()]);
            }
            if(encToDec.find(encodedUrl) == encToDec.end()) {
                decToEnc[longUrl] = encodedUrl;
                encToDec[encodedUrl] = longUrl;
                break;
            }
            if(++count == RETRY) {
                SIZE++;
                count = 0;
            }
        }
        return "http://tinyurl.com/" + decToEnc[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return encToDec[shortUrl.substr(shortUrl.rfind('/') + 1)];
    }
};

/*
글자 수가 유동적으로 변하므로 충돌 문제를 해결할 수 있습니다.

 

모든 데이터를 압축한다면, 저장 공간을 더욱 효율적으로 사용할 수 있을 것입니다.
대신 연산량에서 손해를 보게 됩니다.
*/

class Solution {
public:
    map<string, string> encToDec;
    map<string, string> decToEnc;
    
    string characters = "abcdeafghijklmnopABCDEFGHIJKLMNOP0123456789";
    
    int RETRY = 3;
    int SIZE = 6;
    
    Solution() {
        srand((unsigned int)time(NULL));
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string compressedLongUrl = compress(longUrl);
        if(decToEnc.find(compressedLongUrl) != decToEnc.end())
            return "http://tinyurl.com/" + recover(decToEnc[compressedLongUrl]);
        
        int count = 0;
        while(1) {
            string encodedUrl = "";
            for(int i=0; i<SIZE; i++) {
                encodedUrl.push_back(characters[rand() % characters.size()]);
            }
            string compressedEncodedUrl = compress(encodedUrl);
            if(encToDec.find(compressedEncodedUrl) == encToDec.end()) {
                decToEnc[compressedLongUrl] = compressedEncodedUrl;
                encToDec[compressedEncodedUrl] = compressedLongUrl;
                break;
            }
            if(++count == RETRY) {
                SIZE++;
                count = 0;
            }
        }
        return "http://tinyurl.com/" + recover(decToEnc[compressedLongUrl]);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return recover(
            encToDec[compress(shortUrl.substr(shortUrl.rfind('/') + 1))]
        );
    }
    
private:
    string compress(string str) {
        return "!" + str;
    }
    
    string recover(string str) {
        return str.substr(1);
    }
};

/*
실제로 압축 알고리즘을 작성한 것은 아닙니다. 직접 작성하기엔 너무 어렵습니다.


위 코드들은 수행 시간을 개선하기 위해 map 대신 unordered_map을 사용해도 됩니다.
계층별로 분리하고 복원된 url을 캐시할 수 있다면, 연산량과 저장 공간 측면에서 더욱 이점을 얻을 것으로 보입니다.
 

https://leetcode.com/problems/encode-and-decode-tinyurl/discuss/1974132/c%2B%2B-gradual-improvement-solution
처음으로 리트코드 discuss에도 올려보았습니다.
*/