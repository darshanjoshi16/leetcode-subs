class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rsum = accumulate(nums.begin(), nums.end(), 0);

        int sz = nums.size();
        for (int i = 0, lsum = 0; i < sz; ++i) {
            rsum -= nums[i];
            if (i > 0) lsum += nums[i-1];
            if (rsum == lsum) return i;
        }
        return -1;
    }
};
