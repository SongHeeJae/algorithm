/*
각 노드의 부모 노드를 찾아주고, 사이클이 없는 상황에서의 루트 노드를 찾아줍니다.
루트 노드에서 dfs로 노드를 탐색했을 때, 모든 노드를 1회만 방문할 수 있는지 확인해줍니다.
*/

class Solution {
public:
    int p[10000];

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        memset(p, -1, sizeof(p));
        for(int i=0; i<n; i++) {
            if(leftChild[i] != -1) {
                p[leftChild[i]] = i;
            }
            if(rightChild[i] != -1) {
                p[rightChild[i]] = i;
            }
        }

        int root = 0;
        while(p[root] >= 0) {
            int temp = root;
            root = p[root];
            p[temp] = -1;
        }

        return dfs(n, leftChild, rightChild, root) == n;
    }


    int dfs(int n, vector<int>& leftChild, vector<int>& rightChild, int node) {
        if(node == -1) return 0;
        if(p[node] == -2) return -1;
        p[node] = -2;
        return 1 + dfs(n, leftChild, rightChild, leftChild[node]) + dfs(n, leftChild, rightChild, rightChild[node]);
    }
};
