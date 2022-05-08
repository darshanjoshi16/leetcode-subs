class Solution {
public:
	int n;
	int dp[1002];
	int solve(vector<int>& nums, int left)
	{
		if(left == 0)
			return 1;

		int &ret = dp[left];
		if(~ret)
			return ret;

		ret = 0;
		for (int i = 0; i < n;++i)
		{
			if (nums[i] <= left)
				ret += solve(nums, left - nums[i]);
		}
		return ret;
	}

	int combinationSum4(vector<int>& nums, int target)
	{
		n = nums.size();
		memset(dp, -1, sizeof(dp));
		return solve(nums, target);
	}
};
