#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string& a, string& b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> convert;
    for(int i=0; i<numbers.size(); i++) convert.push_back(to_string(numbers[i]));
    sort(convert.begin(), convert.end(), comp);
    for(int i=0; i<convert.size(); i++) answer += convert[i];
    return answer[0] == '0' ? "0" : answer;
}

/*
두 숫자를 앞 또는 뒤로 합쳤을 때, 더 큰 숫자가 나오는 상황으로 정렬시켜주었습니다. 
*/