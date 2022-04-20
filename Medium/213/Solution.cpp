class Solution {
public:
    int rob(vector<int>& nums)
{
    if(nums.size() == 1) return nums[0];  // If only one house is there, only that will be robbed
    
    int dp1[nums.size()];  // This array will keep track the record of maximum money can be robbed from house[1] to house[n-1] as the houses are circularly arranged which makes house[1] and house[n-1] neighbours.
    dp1[0] = 0; dp1[1] = nums[0];
    
    for(int i = 2; i < nums.size(); i++)
    {
        dp1[i] = max(nums[i-1]+dp1[i-2], dp1[i-1]);
    }
    
    int dp2[nums.size()];   // This array will keep track the record of maximum money can be robbed from house[2] to house[n].
    dp2[0] = 0; dp2[1] = nums[1];
    
    for(int i = 2; i < nums.size(); i++)
    {
        dp2[i] = max(nums[i]+dp2[i-2], dp2[i-1]);
    }
    
    return max(dp1[nums.size()-1], dp2[nums.size()-1]);
}
};
