class Solution {
    vector< vector<int> > dp;
    int f;
    int  n =0;
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        f=fee;
        n = prices.size();
        dp.resize(n , vector<int>(2,-1));
       return  solve(prices,0,0);
       
    }
    
   int  solve( vector<int>& prices,int i , int own)
    {
        if( i >= n) // days fininshef
            return 0;
       if(dp[i][own] != -1)
           return dp[i][own] ;
        if(!own) // 2 options, buy or dont buy
        {
            //buy , subtract buying price and fees and add the max collection from recursion
            int  a =  -(prices[i] + f) + solve(prices, i+1, 1);
            //dont buy
            int b = solve(prices, i+1,0);
            return dp[i][own] =  max(a,b);
            
        }
        else if(own ==1) // sell or dont sell
        {
            // sell , add selling price (collected money)  s and add the max collection from recursion
            int  a =  prices[i]  + solve(prices, i+1, 0);
            //dont sell
            int b = solve(prices, i+1,1);
            return dp[i][own] =  max(a,b);
            
        }
       return 0;
            
        
    }
};
