class Solution {
private:
    bool inBounds(vector<vector<int>> &grid, int i, int j){
        return i >= 0 && i < grid.size() && j >= 0 && j < grid.at(i).size();
    }
    
    int max_nearestWaterCell(vector<vector<int>> &grid, queue<pair<int, int>> &coords){
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        int maxDist = 0;
        while(!coords.empty()){
            int size = coords.size();
            bool isFound = false;
            
            for(int i = 0; i < size; i++){
                pair<int, int> coord = coords.front();
                coords.pop();
                
                int x = coord.first, y = coord.second;
                
                for(vector<int> &dir : dirs){
                    int newX = dir.at(0) + x, newY = dir.at(1) + y;
                    
                    if(!inBounds(grid, newX, newY) || grid.at(newX).at(newY) == 1) continue;
                    
                    coords.push({newX, newY});
                    grid.at(newX).at(newY) = 1;
                    isFound = true;
                }
            }
            
            maxDist += isFound ? 1 : 0;
        }
        
        return maxDist != 0 ? maxDist : -1;
    }
    
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> coords;
        
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid.at(i).size(); j++)
                if(grid.at(i).at(j) == 1)
                    coords.push({i, j});
        
        return max_nearestWaterCell(grid, coords);
    }
};
