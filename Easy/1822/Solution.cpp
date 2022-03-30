class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        //initiallize the product variable
        float prod = 1;

        //running the loop for vector to multiplying all elements in the vector
    for(int i=0;i<nums.size();i++)
    {
        prod *= nums[i];
        
    }
        
    //checking the various condition for the logic.
    if(prod<0)
    {
        return -1;
    }
    else if(prod>0)
    {
        return 1;
    }
    
    return 0; 
    
        
    }
};
