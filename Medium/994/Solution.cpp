class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        int m = grid[0].size();
        
        int total = 0;
        
        int rotten = 0;
        
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1 || grid[i][j] == 2)
                {
                    total++;
                }
                
                if(grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }
        
        if(total == 0)
            return 0;
        
        int time = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            
            rotten += size;
            
            if(rotten == total)
                return time;
            
            time++;
            
            while(size--)
            {
                auto x = q.front();
                
                q.pop();
                
                int i = x.first;
                
                int j = x.second;
                
                if(i - 1 >= 0 && grid[i - 1][j] == 1)
                {
                    q.push({i - 1, j});
                    
                    grid[i - 1][j] = 2;
                }
                
                if(j - 1 >= 0 && grid[i][j - 1] == 1)
                {
                    q.push({i, j - 1});
                    
                    grid[i][j - 1] = 2;
                }
                
                if(i + 1 <= n - 1 && grid[i + 1][j] == 1)
                {
                    q.push({i + 1, j});
                    
                    grid[i + 1][j] = 2;
                }
                
                if(j + 1 <= m - 1 && grid[i][j + 1] == 1)
                {
                    q.push({i, j + 1});
                    
                    grid[i][j + 1] = 2;
                }
            }
        }
        
        return -1;
    }
};
