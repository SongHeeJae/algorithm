/*
노드를 두 번 순회하면, 추가 공간 없이 결과를 구할 수 있습니다.
주어진 트리는 이진트리이므로, 트리를 중위순회하여 오름차순으로 모든 노드를 방문할 수 있습니다.
처음 순회할 때, 연속적으로 방문되는 노드가 동일한 값을 가지는 최대 길이를 구해주고,
다음으로 순회할 때, 연속적으로 방문되는 노드의 개수가 최대 길이인 값을 구해줍니다.
*/

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        int maxLength = findMaxLength(root);
        return findElementsOfLength(root, maxLength);
    }

    int findMaxLength(TreeNode* root) {
        int val = INT_MIN, curLength = 0, maxLength = 1;
        findMaxLength(root, val, curLength, maxLength);
        return max(curLength, maxLength);
    }

    void findMaxLength(TreeNode* node, int& val, int& curLength, int& maxLength) {
        if(!node) return;
        findMaxLength(node->left, val, curLength, maxLength);
        if(node->val != val) {
            maxLength = max(maxLength, curLength);
            val = node->val;
            curLength = 1;
        } else {
            curLength++;
        }
        findMaxLength(node->right, val, curLength, maxLength);
    }

    vector<int> findElementsOfLength(TreeNode* root, int length) {
        vector<int> elements;
        int val = INT_MIN, curLength = 0;
        findElementsOfLength(root, length, val, curLength, elements);
        return elements;
    }

    void findElementsOfLength(TreeNode* node, int length, int& val, int &curLength, vector<int>& elements) {
        if(!node) return;
        findElementsOfLength(node->left, length, val, curLength, elements);
        if(node->val != val) {
            val = node->val;
            curLength = 1;
        } else {
            curLength++;
        }
        if(curLength == length) {
            elements.push_back(node->val);
        }
        findElementsOfLength(node->right, length, val, curLength, elements);
    }
};


/*
각 value마다 count를 기억해주면, 추가 공간을 사용하여 결과를 구할 수 있습니다.
*/

class Solution {
public:
    unordered_map<int, int> valToLengthMap;
    int maxLength = 0;
    vector<int> findMode(TreeNode* root) {
        preorder(root);
        
        vector<int> res;
        for(auto& p : valToLengthMap) {
            if(p.second == maxLength) res.push_back(p.first);
        }
        return res;
    }

    void preorder(TreeNode* node) {
        if(!node) return;
        maxLength = max(maxLength, ++valToLengthMap[node->val]);
        preorder(node->left);
        preorder(node->right);
    }
};


class Solution {
public:
    unordered_map<int, int> valToLengthMap;
    unordered_map<int, unordered_set<int>> lengthToValuesMap;

    int maxLength = 0;
    vector<int> findMode(TreeNode* root) {
        preorder(root);
        return vector<int>(lengthToValuesMap[maxLength].begin(), lengthToValuesMap[maxLength].end());
    }

    void preorder(TreeNode* node) {
        if(!node) return;
        int& length = valToLengthMap[node->val];
        maxLength = max(maxLength, ++length);
        lengthToValuesMap[length - 1].erase(node->val);
        lengthToValuesMap[length].insert(node->val);
        preorder(node->left);
        preorder(node->right);
    }
};
