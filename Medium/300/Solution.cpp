
    class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1;
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = INT_MIN;

        for (int i = 0; i < n; i++) {
            int length = upper_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            if (nums[i] > dp[length - 1] && nums[i] < dp[length]) {
                dp[length] = nums[i];
                maxi = max(maxi, length);
            }
        }
        return maxi;
    }
};
