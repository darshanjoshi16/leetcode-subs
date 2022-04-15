class Solution {
public:
    int search(vector<int>& nums, int target) {
		int ans = -1;
		int l = 0, r = nums.size() - 1,m=0;
		
		//calculate pivot element using binary search
		while (l < r) {
			m = l + (r - l) / 2;
			if (nums[m] > nums[l] && nums[m] > nums[r])
				l = m;
			else
				r = m;
		}
		
	   // check range in which target may present
		if (target <= nums[m] && target >= nums[0])
			l = 0, r = m;
		else
			l = min(m + 1, (int)nums.size() - 1), r = nums.size() - 1;

		//binary search
		while (l <= r) {
			m = l + (r - l) / 2;
			if (nums[m] == target)
				return m;
			if (target > nums[m])
				l = m + 1;
			else // target < nums[m]
				r = m - 1;
		}
		return ans;
	
    }
};
