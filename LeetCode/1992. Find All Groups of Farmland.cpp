/*
land를 순회하며 직사각형의 좌측상단 꼭짓점인지 판별하고, 해당 지점에서 우측하단 꼭짓점을 찾아줍니다.
*/

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size(), m = land[0].size();
        vector<vector<int>> res;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!isTopLeft(land, i, j)) continue;

                vector<int> temp;
                temp.push_back(i);
                temp.push_back(j);

                while(j < m && land[i][j] == 1) j++;
                
                int k = i;
                while(k < n && land[k][j - 1] == 1) k++;
                
                temp.push_back(k - 1);
                temp.push_back(j - 1);

                res.push_back(temp);
            }
        }
        return res;
    }
private:
    bool isTopLeft(vector<vector<int>>& land, int x, int y) {
        if(land[x][y] != 1) return false;
        return (x == 0 || land[x - 1][y] == 0)
            && (y == 0 || land[x][y - 1] == 0);
    }
};
