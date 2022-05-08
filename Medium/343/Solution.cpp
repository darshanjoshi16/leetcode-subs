class Solution {
public:
    int dp[60];
    int solve(int n){
        /** Base Cases **/
        if(n==0) return 0;
        if(n==1) return 1;
        
        /**Check for repeative function call **/
        if(dp[n]!=-1) return dp[n];
        
        /** Iterate over range **/
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            ans=max(ans,(i)*solve(n-i));
        }
        return dp[n]=ans;
        
    }
    int integerBreak(int n) {
        /** if n==2 then result should be equal to 1 and if n==3 thrn equal to 2. **/
        if(n==2) return 1;
        if(n==3) return 2;
        /** Initialize dp with -1. **/
        memset(dp,-1,sizeof(dp));
        /** Let's call the recursive function **/
        int res=solve(n+1);
        return res;
    }
};
        
    
