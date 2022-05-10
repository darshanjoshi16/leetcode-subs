class Solution {
private:
	void labellingDfs(vector<vector<char>>& grid, int i, int j);
public:
    int numIslands(vector<vector<char>>& grid);
};

void Solution::labellingDfs(vector<vector<char>>& grid, int i, int j)
{
	int m = grid.size();
	int n = grid[0].size();

	// Base case
	if('1' != grid[i][j])
		return;

	// Labelling the grid
	grid[i][j] = '0';

	// Up
	if(i >= 1)
		labellingDfs(grid, i-1, j);

	// Right
	if(j < n - 1)
		labellingDfs(grid, i, j+1);

	// Down
	if(i < m - 1)
		labellingDfs(grid, i+1, j);

	// Left
	if(j >= 1)
		labellingDfs(grid, i, j-1);
}


int Solution::numIslands(vector<vector<char>>& grid)
{
	int res = 0;

	for(int i = 0; i < grid.size(); i++)
	{
		for(int j = 0; j < grid[i].size(); j++)
		{
			// Find a new island
			if('1' == grid[i][j])
			{
				res++;
				labellingDfs(grid, i, j);
			}
		}
	}

	return res;
}
