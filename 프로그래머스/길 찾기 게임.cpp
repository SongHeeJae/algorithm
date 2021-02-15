#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<int>> nodes;
vector<int> pre;
vector<int> post;
map<int, pair<int, int>> trees;

bool comp(vector<int>& a, vector<int>& b) {
    return a[2] > b[2];
}

bool insert(int root, vector<int>& item, vector<vector<int>>& nodeinfo) {
    if(root == -1) return true;
    if(nodeinfo[root][0] > item[1]) {
        if(insert(trees[root].first, item, nodeinfo))
            trees[root].first = item[0];
    } else {
        if(insert(trees[root].second, item, nodeinfo))
            trees[root].second = item[0];
    }
    return false;
}

void preorder(int node) {
    if(node != -1) {
        pre.push_back(node+1);
        preorder(trees[node].first);
        preorder(trees[node].second);
    }
}

void postorder(int node) {
    if(node != -1) {
        postorder(trees[node].first);
        postorder(trees[node].second);
        post.push_back(node+1);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    for(int i=0; i<nodeinfo.size(); i++) {
        nodes.push_back({i, nodeinfo[i][0], nodeinfo[i][1]});
        trees[i] = {-1, -1};
    }
    sort(nodes.begin(), nodes.end(), comp);
    for(int i=1; i<nodes.size(); i++)
        insert(nodes[0][0], nodes[i], nodeinfo);
    preorder(nodes[0][0]);
    postorder(nodes[0][0]);
    return {pre, post};
}

/*
먼저 각 노드에 번호를 붙인 후, 이진트리에 들어가야할 레벨 별로 정렬해준 뒤,
x값을 기준으로 삽입하여 이진 트리 구조를 만들었습니다.
이진트리는 map을 이용해서 구현하였습니다.
*/