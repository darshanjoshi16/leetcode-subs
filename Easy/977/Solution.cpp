class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        //initialize the count of element of vector of nums 
        int n = nums.size();
        
        //initialize the vector which is resultant
        vector<int> result;
        
        //consider these 2 variables as pointers and further calculation using 2 pointer approach
        int l = 0;
        int h = n - 1;
        
        //logic for pushing the squared value according to 2 pointer approach
        while(l <= h)
        {
           if(abs(nums[l]) > abs(nums[h])){
               result.push_back(nums[l] * nums[l]);
               l++;
           } 
           else{
                result.push_back(nums[h] * nums[h]);
                 h--;
           }
        }
        
        //sorting the whole vector in ascending order
        reverse(result.begin() , result.end());
        
        return result;
    }
};
