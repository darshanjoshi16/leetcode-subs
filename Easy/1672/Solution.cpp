class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
         
      //assigning the maximum value to minimum value in integer
        int maxi = INT_MIN;
      //traversing the 2-D vector
        for(int i =0 ; i < accounts.size(); i++)
        {
            int sum = 0;
            for(int j = 0; j < accounts[0].size(); j++)
            {
                sum += accounts[i][j];
            }
          
          //determining the maximum values among the vectors
            maxi = max(sum, maxi);
        }
        return maxi;
        
    }
};
