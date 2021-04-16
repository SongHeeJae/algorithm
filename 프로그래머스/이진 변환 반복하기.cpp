#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int ans1 = 0, ans2 = 0;

string levelOne(string& x) {
    string ret = "";
    for(int i=0; i<x.size(); i++)
        if(x[i] == '1') ret.push_back('1');
        else ans2++;
    return ret;
}

string levelTwo(string x) {
    string ret = "";
    int len = x.size();
    while(len != 0) {
        if((len & 1) == 0) ret.push_back('0');
        else ret.push_back('1');
        len = len >> 1;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string translate(string& x) {
    return levelTwo(levelOne(x));
}

vector<int> solution(string s) {
    while(1) {
        s = translate(s);
        ans1++;
        if(s == "1") break;
    }
    return {ans1, ans2};
}