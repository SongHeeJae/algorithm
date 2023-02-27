/*
재귀적으로 n을 절반씩 줄여나가며, 현 범위 내의 grid가 leaf인지 검사해줍니다.
leaf라면, Quad Tree 노드를 생성하여 반환해주고,
leaf가 아니라면, Quad Tree 노드의 자식 노드 4개를 다시 생성하여 동일한 재귀 작업을 수행해줍니다.
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return create(grid, 0, 0, grid.size());
    }
private:
    Node* create(vector<vector<int>>& grid, int x, int y, int sz) {
        if(sz == 0) {
            return NULL;
        }
        
        if(isLeaf(grid, x, y, sz)) {
            return new Node(grid[x][y], true);
        }
        else {
            int nsz = sz / 2;
            return new Node(
                1, 
                false,
                create(grid, x, y, nsz), 
                create(grid, x, y + nsz, nsz), 
                create(grid, x + nsz, y, nsz), 
                create(grid, x + nsz, y + nsz, nsz)
            );
        }
    }

    bool isLeaf(vector<vector<int>>& grid, int x, int y, int sz) {
        int val = grid[x][y];
        for(int i=x; i<x+sz; i++) {
            for(int j=y; j<y+sz; j++) {
                if(val != grid[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};
