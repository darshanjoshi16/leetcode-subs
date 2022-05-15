class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        // Number of Rows in maze
        int m = maze.size();
        
        //Number of Columns in maze
        int n = maze[0].size();
        
        // Distance Matrix to track distance of cells from entrance
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        // Setting the distance of entrance as 0;
        dist[entrance[0]][entrance[1]] = 0;
        
        
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};
        
        // Queue to run BFS
        queue<pair<int,int>> q;
        
        // Pushing base element in queue. Here Base element is Entrance Coordinates
        q.push(make_pair(entrance[0], entrance[1]));
        
        // Running the BFS
        while(!q.empty()) {
            int l = q.size();
            while(l--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                      
                for(int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] == '.') {
                        maze[nx][ny] = '+';
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push(make_pair(nx, ny));
                    }
                }
            } 
        }
        int minDis = INT_MAX;
        
        
        
        // If entrance is at border so we have to neglect it. So assigning INT_MAX
        dist[entrance[0]][entrance[1]] = INT_MAX;
        for(int i = 0; i < m; i++) {
            minDis = min(dist[i][0], minDis);
            minDis = min(dist[i][n-1], minDis);
        }
        for(int i = 0; i < n; i++) {
            minDis = min(dist[0][i], minDis);
            minDis = min(dist[m-1][i], minDis);
        }

        
        if(minDis == INT_MAX) 
        {
            minDis = -1;
        }
        return minDis;
    }
};
