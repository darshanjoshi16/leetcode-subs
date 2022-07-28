class Solution {
public:
   int path(int i,int j,int n,int m,vector<vector<int>>& grid) {
        if(i == n) return j;
        if(j == 0 && grid[i][j] == -1) return -1;
        if(j == m-1 && grid[i][j] == 1) return -1;
        if(grid[i][j] == -1) {
            if(grid[i][j-1] == -1) {
                return path(i+1,j-1,n,m,grid);
            } else {
                return -1;
            }
        }
        if(grid[i][j] == 1) {
            if(grid[i][j+1] == 1) {
                return path(i+1,j+1,n,m,grid);
            } else {
                return -1;
            }
        }
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<m;i++){
            ans.push_back(path(0,i,n,m,grid));
        }
        return ans;
    }
};
