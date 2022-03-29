class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        //count of zero
        int j=0;
        int n=nums.size();
        // iterating through the string
        for(int i=0;i<n;i++)
        {
            // if we encounter a non zero element, place it in jth index and then increment j
            if(nums[i]!=0)
            {
                nums[j]=nums[i];
                j++;
            }
        }
        // now after the iteration all non zero elements are filled and now we will fill all the 0s untill we get the value of j becomes equal to original size of vector
        while(j<n)
        {
            nums[j]=0;
            j++;
        }
        
        
    
        
    }
};
