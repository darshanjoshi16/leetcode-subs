class Solution {
public:
    int sum(int x, int y, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
       if(x>=m||x<0||y>=n||y<0)
            return INT_MAX;
        if(dp[x][y]!=INT_MAX)
            return dp[x][y];
        
        dp[x][y]=grid[x][y]+min(sum(x-1,y,m,n,grid,dp),sum(x,y-1,m,n,grid,dp));
        return dp[x][y];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));//stores min sum uptil index
        dp[0][0]=grid[0][0];
        return sum(m-1,n-1,m,n,grid,dp);
        
    }
};
