class Solution {
public:
    // The basic idea is just find one one the island and push all the nodes of that island
    // in queue. 
    
    // Now from each node of that island move one step in all directions. if neighbour of any
    // of the node in queue is the node of second island then return the total steps
    // we travelled.
    
    // Else push those adjacent nodes in queue and repeat the same process until we reach at
    // any node of second island
    
    
    // storing all nodes of one island in queue using dfs
    void dfs(int i,int j,int n,queue<pair<int,int>> &q, vector<vector<int>> &vis, vector<vector<int>>& grid){
        
        if(i<0 || j<0 || i>=n || j>=n || vis[i][j] == 1 || grid[i][j] == 0){
            return;
        }
        
        vis[i][j] = 1;
        q.push({i,j});

        dfs(i,j+1,n,q,vis,grid);
        dfs(i,j-1,n,q,vis,grid);
        dfs(i+1,j,n,q,vis,grid);
        dfs(i-1,j,n,q,vis,grid);
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        
        queue<pair<int,int>> q;
        
        int f = 0;
        
        // find first node of one of the island to store it in queue.
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    f=1;
                    
                    dfs(i,j,n,q,vis,grid);
                    break;
                }
            }
            if(f){
                break;
            }
        }
        
        int step = 0;
        
        // array to move in all directions
        int a[4] = {0,0,-1,1};
        int b[4] = {1,-1,0,0};
        
        while(!q.empty()){
            
            int s = q.size();
            
            while(s--){
                
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                // move in all directions
                for(int i=0;i<4;i++){
                    int x_new = x + a[i];
                    int y_new = y + b[i];
                    
                    // check out of bound and visited condition
                    if(x_new >= 0 && y_new >= 0 && x_new < n && y_new < n && vis[x_new][y_new] == 0){
                        
                        // we get the one of the node of second island
                        if(grid[x_new][y_new] == 1){
                            return step;        
                        }
                        
                        q.push({x_new,y_new});
                        vis[x_new][y_new] = 1;
                    }
                }
            }
            step++;
        }
        
        return -1;
    }
};
