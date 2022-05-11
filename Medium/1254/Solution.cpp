class Solution {
public:
    void helper(int i , int j , vector<vector<int>> &vis , vector<vector<int>>&grid){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size()) return;
        if(vis[i][j]==-1 or grid[i][j]==1) return;
        vis[i][j] = -1;
        helper(i , j-1 , vis , grid);
        helper(i , j+1 , vis , grid);
        helper(i-1 , j , vis , grid);
        helper(i+1 , j , vis , grid);
    }
    void bfs(int i ,int j , vector<vector<int>> &vis , vector<vector<int>> &grid){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size()) return;
        if(vis[i][j]==-1 or vis[i][j]==1 or grid[i][j]==1) return;
        vis[i][j] = 1;
        bfs(i , j-1 , vis , grid);
        bfs(i , j+1 , vis , grid);
        bfs(i-1 , j , vis , grid);
        bfs(i+1 , j , vis , grid);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n ,vector<int>(m,0));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(i==0 and grid[i][j]==0 and vis[i][j]!=-1){
                    helper(i , j , vis , grid);
                }
                if(i==n-1 and grid[i][j]==0 and vis[i][j]!=-1){
                    helper(i , j , vis , grid);
                }
                if(j==0 and grid[i][j]==0 and vis[i][j]!=-1){
                    helper(i , j , vis , grid);
                }
                if(j==m-1 and grid[i][j]==0 and vis[i][j]!=-1){
                    helper(i , j , vis , grid);
                }
            }
        }
        
        int ct = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(vis[i][j]==0 and grid[i][j]==0){
                    bfs(i , j , vis , grid);
                    ct++;
                }
            }
        }
        
        return ct;
    }
};
