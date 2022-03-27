class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        //initialize the variables for traversing the vector
        int start = 0, end = nums.size()-1;
        
        //we will be using the iterative way to do the binary search
        //run the loop till start exceeds the end
        while(start<=end)
        {
            //calculating the mid point
           int  mid_point = start + (end-start)/2;
            
            //if the value we get at mid index is equal to target then return the result
            if(nums[mid_point]==target)
            {
                return mid_point;
            }
            
            //if the value is less than target, you can divide the array into subarray where starting index will be one position after the mid value so the target value must be in range of new start and end value
            else if(nums[mid_point]<target)
            {
                start = mid_point + 1;
            }
            
            //if the value is greater than target, you can divide the array into subarray where ending index will be one position before the mid value so the target value must be in range of  start and new end value
            else
            {
                end = mid_point - 1;
            }
        }
        
        //if the target is not available in the array
        return -1;
        
        
    }
};
