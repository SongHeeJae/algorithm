#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

bool compare(pair<string, pair<int, int>>& a, pair<string, pair<int, int>>& b) {
    if(a.first == b.first) {
        if(a.second.first == b.second.first) {
            return a.second.second < b.second.second;
        } else {
            return a.second.first > b.second.first;
        }
    } else {
        return a.first < b.first;
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<string, pair<int, int>>> songs;
    map<string, int> nums;
    priority_queue<pair<int, string>> pq;
    for(int i=0; i<plays.size(); i++) {
        songs.push_back({genres[i],{plays[i], i}});
        auto num = nums.find(genres[i]);
        if(num != nums.end()) {
            num->second += plays[i];
        } else {
            nums.insert({genres[i], plays[i]});
        }
    }
    for(auto it = nums.begin(); it != nums.end(); it++) {
        pq.push({it->second, it->first});
    }
    sort(songs.begin(), songs.end(), compare);
    while(!pq.empty()) {
        string genre = pq.top().second;
        pq.pop();
        int cnt = 0;
        for(int i=0; i<songs.size(); i++) {
            if(songs[i].first == genre) {
                answer.push_back(songs[i].second.second);
                cnt++;
                if(cnt == 2) break;
            }
        }
    }
    return answer;
}