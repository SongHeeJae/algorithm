/*
지그재그 경로라면 누적된 길이에 1 더해주고, 그렇지 않다면 길이를 초기화해줍니다.
경로의 최대 길이를 구해줍니다.
*/

class Solution {
public:
    int longestZigZag(TreeNode* root) {
        return longestZigZag(root, false, 0);
    }

    int longestZigZag(TreeNode* node, bool left, int cnt) {
        return node ? max({
            cnt,
            longestZigZag(node->right, false, left ? cnt + 1 : 1),
            longestZigZag(node->left, true, left ? 1 : cnt + 1)
        }) : cnt - 1;
    }
};
