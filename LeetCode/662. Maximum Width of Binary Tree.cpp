/*
bfs를 이용하여 풀었습니다.
탐색하는 노드에 완전 이진 트리 형태로 인덱스 번호를 붙여줍니다.
가장 우측 노드의 인덱스와 가장 좌측 노드의 인덱스 번호의 차이를 이용하여 width를 구할 수 있습니다.
*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int mx = 1;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            int sz = q.size();
            int left = q.front().second;
            int right = q.back().second;
            mx = max(mx, right - left + 1);
            while(sz--) {
                TreeNode* node = q.front().first;
                int idx = q.front().second;
                q.pop();

                if(node->left) q.push({node->left, (long long) idx * 2 + 1});
                if(node->right) q.push({node->right, (long long) idx * 2 + 2});
            }
        }
        return mx;
    }
};


