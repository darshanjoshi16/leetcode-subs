class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
    
    int n=matrix.size();
    int m=matrix[0].size();
    int maxLen = 0;
    vector<vector<int>>dp(n, vector<int>(m, 0));
    
    for(int i=0;i<m;i++)
        if(matrix[n-1][i]=='1'){
            dp[n-1][i] = 1;
            maxLen = 1;
        }
    
    for(int i=0;i<n;i++)
        if(matrix[i][m-1]=='1'){
            maxLen = 1;
            dp[i][m-1] = 1;
        }
    
    for(int i=n-2;i>=0;i--)
        for(int j=m-2;j>=0;j--)
            if(matrix[i][j] == '1'){
                dp[i][j] = 1 + min({dp[i+1][j], dp[i+1][j+1], dp[i][j+1]});
                maxLen = max(maxLen, dp[i][j]);
            }
                    
    return (maxLen*maxLen);
}
};
