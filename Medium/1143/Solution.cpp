class Solution {
public:
   int lcsDp(string &x , string&y, int m , int n){
        int dp[m+1][n+1];
        //Initialization
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0||j==0)dp[i][j]=0;
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(x[i-1] == y[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1]; 
                }else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
         return lcsDp(text1,text2,text1.size(),text2.size());       
    }
};
