class Solution {
private:
    bool isSurrounded(vector<vector<int>> &grid, int i, int j, int &landCount){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid.at(i).size()) return false;
        
        if(grid.at(i).at(j) == 0) return true;
        
        grid.at(i).at(j) = 0;
        
        landCount++;
        
        bool up    = isSurrounded(grid, i - 1, j, landCount);
        bool down  = isSurrounded(grid, i + 1, j, landCount);
        bool left  = isSurrounded(grid, i, j - 1, landCount);
        bool right = isSurrounded(grid, i, j + 1, landCount);
        
        return up && down && left && right;
    }
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int landCells = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid.at(i).size(); j++){
                int landCount = 0;
                
                if(grid.at(i).at(j) == 1 && isSurrounded(grid, i, j, landCount))
                    landCells += landCount;
            }
        }
        
        return landCells;
    }
};
