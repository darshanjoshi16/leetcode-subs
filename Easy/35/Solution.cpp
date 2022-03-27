class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        //initialize the index variable
        int index = -1;
        
        //sorting the vector will be helpful in finding the index and also it will helpfull to determine the index where the data should be entered
        sort(nums.begin(),nums.end());
        
        //iterating the loop over the vector
        for(int i = 0; i < nums.size() ; i++)
        {
            //if we found the target value matching with ith value of array or ith value is greater than target will assignn updated index
            if(target == nums[i] || nums[i] > target)
            {
                index = i;
                break;
            }
        }
        
        // if the target element is not in the array then return the index where it should be entered
        if(index == -1)
        {
            index = nums.size();
        }
        
        return index;
    }
};
