#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    for(int i=0; i<progresses.size();) {
        
        int days = (100.0 - progresses[i]) / speeds[i];
        int cnt = 0;
        bool flag = true;
        for(int j=i; j<progresses.size(); j++) {
            progresses[j] += speeds[j] * days;
            if(progresses[j] < 100) flag = false;
            if(flag && progresses[j] >= 100) cnt++;
        }
        answer.push_back(cnt);
        i += cnt;
    }
    return answer;
}