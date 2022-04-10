/*
주어진 연산에 알맞게 수행해주면 되었습니다.
*/

class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sum = 0;
        vector<int> scores;
        for(string& op : ops) {
            if(op == "C") {
                sum -= scores.back();
                scores.pop_back();
            } else {
                scores.push_back(get(scores, op));
                sum += scores.back();
            }
        }
        return sum;
    }
    
    int get(vector<int>& scores, string& op) {
            if(op == "+") return scores.back() + *(scores.rbegin() + 1);
            else if(op == "D") return scores.back() * 2;
            else return stoi(op);
    }
};
