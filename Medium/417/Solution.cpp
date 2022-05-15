class Solution {
    vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    const char unknown = ' ';
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights.front().size();
        
        vector<vector<char>> region(m, vector<char>(n, unknown));
        
        vector<vector<int>> result;
        function<void(int, int, char)> dfs = [&](int i, int j, char ocean) {
            if (region[i][j] == ocean) return;
			
			// check if the entry is also in another ocean region
            if (region[i][j] != unknown) result.push_back({i, j});
            
            region[i][j] = ocean;
            
            for (auto [di, dj] : directions) {
                int ii = i + di;
                int jj = j + dj;
                if (ii < 0 || ii >= m || jj < 0 || jj >= n) continue;
                if (heights[ii][jj] < heights[i][j]) continue;
                
                dfs(ii, jj, ocean);
            }
        };
        
		// search for pacific region
        for (int j = 0; j < n; ++j) dfs(0, j, 'p');
        for (int i = 0; i < m; ++i) dfs(i, 0, 'p');
		
		// search for atlantic region
        for (int j = 0; j < n; ++j) dfs(m - 1, j, 'a');
        for (int i = 0; i < m; ++i) dfs(i, n - 1, 'a');
        
        return result;
    }
};
