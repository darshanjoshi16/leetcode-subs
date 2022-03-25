class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        //it will sort the number <vector>
        sort(nums.begin(),nums.end());
            
        
        //it will run the loop till the end of<vector>
        for(int i=1;i<nums.size();i++)
        {
            //comparing the adjacent numbers
            //if atleast twice they are appearing then,this condition will return true
            if(nums[i]==nums[i-1])
            {
                return true;
            }
            
            
        }
       return false; 
    }
};
