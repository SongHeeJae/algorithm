/*
모든 노드를 순회하면서, 동일한 열의 노드들을 저장해줍니다.
이 때, 노드의 행 번호도 같이 저장해주고, 정렬 기준으로 사용하였습니다. 
*/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> m;
        traverse(root, 0, 0, m);
        
        vector<vector<int>> result;
        for(auto p1 : m) {
            sort(p1.second.begin(), p1.second.end(), [](auto& a, auto& b) -> bool {
                return a.first == b.first ? a.second < b.second : a.first < b.first;
            });
            
            vector<int> temp;
            for(auto p2 : p1.second) temp.push_back(p2.second);
            result.push_back(temp);
        }
        return result;
    }
    
    void traverse(TreeNode* node, int row, int col, map<int, vector<pair<int, int>>>& m) {
        if(!node) return;
        traverse(node->left, row + 1, col - 1, m);
        m[col].push_back({row, node->val});
        traverse(node->right, row + 1, col + 1, m);
    }
};



/*
정렬된 상태를 위해 multiset을 이용할 수도 있었습니다.
*/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> m;
        traverse(root, 0, 0, m);
        
        vector<vector<int>> result;
        for(auto p1 : m) {
            vector<int> temp;
            for(auto p2 : p1.second)
                temp.insert(temp.end(), p2.second.begin(), p2.second.end());
            result.push_back(temp);
        }
        return result;
    }
    
    void traverse(TreeNode* node, int row, int col, map<int, map<int, multiset<int>>>& m) {
        if(!node) return;
        traverse(node->left, row + 1, col - 1, m);
        m[col][row].insert(node->val);
        traverse(node->right, row + 1, col + 1, m);
    }
};
