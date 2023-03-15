/*
DFS로 풀 수 있었습니다.
리프 노드까지 수를 만들어주고, 리프 노드에 도달하면 만들어진 수를 반환해줍니다.
모든 경로에서 만들어진 수를 더해줍니다.
*/

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int temp = 0;
        return sumNumbers(root, temp);
    }

    int sumNumbers(TreeNode* node, int& temp) {
        if(!node) return 0;
        
        temp = temp * 10 + node->val;

        int sum = !node->left && !node->right ? temp : 0;
        sum += sumNumbers(node->left, temp);
        sum += sumNumbers(node->right, temp);

        temp /= 10;

        return sum;
    }
};
