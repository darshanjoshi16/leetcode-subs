class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        //initiliaze the total sum and sum at current positon
        int summation = nums[0], currSum = nums[0];
        
        //running the loop till the end of the vector is traversed
        for(int i=1; i<nums.size();i++)
        {
            //it will set the current maximum with max function comparing the value of current value and after addition with currSum's previous value
            currSum = max(currSum + nums[i],nums[i]);
            
            //it will check the maximum among the total summmation and summation at current situation
            summation = max(summation,currSum);
        }
        
        return summation;
    }
};
