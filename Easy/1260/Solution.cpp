class Solution {
public:
    
    //creating the vector which is taking the grid vector as input and number of places it want to change places
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) 
    {
        //size of the rows in the vector
        int n=grid.size();
        
        //size of the columns in the vector
        int m=grid[0].size();
        
        //creating the resultant vector for storing the final array
        vector<vector<int>> ans(n,vector<int>(m));
        
        //traversing the for loop till we will traverse the whole vector
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //it is creating the new J value of regarding the given comment
                
                int newJ=(j+k)%m; // (j + numbers of columns added)%m
                
                //it is creating the new I value of regarding the given comment
                
                int newI=(i+(j+k)/m)%n; // (i + numbers of rows added)%n 
                
                //assigning the elements to new resultant array
                ans[newI][newJ]=grid[i][j];
            }
        }
        return ans;
    }
};
