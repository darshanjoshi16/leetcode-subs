class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        //least value so far for prices array
        int least_so_far = INT_MAX;
        
        //initialize the overall profit value
        int overall_profit = 0;
        
        //profit if sold in current day
        int profit_current_day = 0;
        
        for(int i = 0; i < prices.size(); i++)
        {
            //if the value in vector is lesser then least so far then it will assign the value of price[i] to variable
            //which means we are finding the new buying value which is lesser than current buying price;
            if(prices[i]<least_so_far)
            {
                least_so_far = prices[i];
            }
            
            //it will assign the profit value of current day to variable ( buy value - sell value)
            profit_current_day = prices[i] - least_so_far;
            
            //it will update the profit value into overall profit variable
            if(overall_profit < profit_current_day)
            {
                overall_profit = profit_current_day;
            }
            
        }
        
        return overall_profit;
    }
};
