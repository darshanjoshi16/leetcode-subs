class Solution {
public:
    int rob(vector<int>& nums) {
        
        int dp[nums.size()];
        
        //base case
        if(nums.size()==1) return nums[0];
        
        //initial case
        dp[0]=nums[0];
        dp[1]= nums[1]<nums[0] ? nums[0]:nums[1];
        
        //further recursion
        for(int i=2;i<nums.size();i++){
            dp[i]= max(dp[i-1],nums[i]+dp[i-2]); 
        }
        return dp[nums.size()-1];
        
    }
};
