class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0];
        int profit = 0;
        int i = 1;
        int temp = 0;
        while(i < n){
            if(prices[i] < buy || (temp >= prices[i] - buy)){
                profit+=temp;
                temp = 0;
                buy = prices[i];
            }
            else{
                temp = prices[i] - buy;
                
            }
            i+=1;
            
        }
        if(temp!=0){
            profit+=temp;
        }
        
        
        return profit;
    }
};
