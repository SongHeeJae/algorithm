/*
dfs로 풀었습니다. 각 노드가 받아야하는 코인은 음수, 줘야하는 코인은 양수로 반환이 됩니다.
좌측 노드, 우측 노드, 자신이 줘야하는 코인의 합이 이동해야하는 코인의 개수가 됩니다.
*/

class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int move = 0;
        distributeCoins(root, move);
        return move;
    }
private:
    int distributeCoins(TreeNode* node, int& move) {
        if(!node) return 0;
        int res = distributeCoins(node->left, move) + distributeCoins(node->right, move) + node->val - 1;
        move += abs(res);
        return res;
    }
};
