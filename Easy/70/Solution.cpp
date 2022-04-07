class Solution 
{
public:
    //defining the dp array for the constraint of n <= 45
    int dp[46] ;
    
    int climbStairs(int n) 
    {
        //defining the base condition method
        if(n == 1 || n == 2){
            return n;
        }
        
        //after further iteration of recursion
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3;i<=n;i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
