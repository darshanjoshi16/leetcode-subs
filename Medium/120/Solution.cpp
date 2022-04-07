class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        //triangle vector size initialization
        int n=triangle.size();
    
        //creating the vector
        vector<int> dp(n+1,0);
    
    //logic for the minimum path sum
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<triangle[i].size();j++)
            dp[j]=triangle[i][j]+min(dp[j],dp[j+1]);
    }
    
    return dp[0];
}
        
};
