/*
n depth를 가지는 트리 구조로 보면 됩니다.
각 노드가 0일 때에는 (0, 1), 1일 때에는(1, 0)의 하위 노드를 가지고, 루트 노드는 0입니다.
상위 노드가 0이었다면, 하위 노드 k가 홀수일 때 0, 짝수일 때 1의 값을 가지게 됩니다.
상위 노드가 1이었다면, 하위 노드 k가 홀수일 때 1, 짝수일 때 0의 값을 가지게 됩니다.
n depth, k번 노드의 상위 노드는, (n-1) depth, ((k + 1) / 2)번 노드가 됩니다.
*/

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1) return 0;
        return kthGrammar(n - 1, (k + 1) / 2) ? k % 2 : !(k % 2);
    }
};
