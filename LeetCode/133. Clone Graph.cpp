/*
DFS를 이용하여 풀었습니다.
이미 클론한 노드는 따로 저장해두고, 재방문하게 되면 클론된 노드를 반환해줍니다. 
*/

class Solution {
private:
    Node* visit[101];
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        if(visit[node->val]) return visit[node->val];

        Node* clonedNode = new Node(node->val);
        visit[node->val] = clonedNode;

        for(Node* neighbor : node->neighbors)
            clonedNode->neighbors.push_back(cloneGraph(neighbor));

        return clonedNode;
    }
};
