class Solution {
public:
    
    int func(vector<int>& prices,int index,int n,bool bought,vector<vector<int>> &dp){
        if(index>=n){
            return 0;
        }
        if(dp[index][bought]!=-1){
            return dp[index][bought];
        }
        if(bought){
            //sell or not sell
            return dp[index][bought] = max(prices[index]+func(prices,index+2,n,false,dp),func(prices,index+1,n,true,dp));
        }
        else{
            //buy or not buy
            return dp[index][bought] = max(-prices[index]+func(prices,index+1,n,true,dp),func(prices,index+1,n,false,dp));
        }
    }
    
    int maxProfit(vector<int>& prices) {
        int n  = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return func(prices,0,n,false,dp);
    }
};
