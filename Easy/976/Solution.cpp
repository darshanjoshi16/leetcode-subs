class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        
        //first of all we will sort the vector because we will consider Heron's Formula for triangles
        //greater<int> is a functional struct which will compare the greater element in nums vector
        sort(nums.begin(),nums.end(), greater<int>());
         
        //it will run for size of vector - 2 because triangle has 3 sides and for any triangle we cant  take except multiples of 3
        for(int i = 0; i < nums.size()-2;i++)
        {
            //checking the condition for non-zero area triangle
            if(nums[i]<nums[i+1]+nums[i+2])
            {
                return nums[i]+nums[i+1]+nums[i+2];
            }
        }
        
        return 0;
    }
};
