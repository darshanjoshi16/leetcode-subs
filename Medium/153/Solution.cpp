class Solution {
public:
    int findMin(vector<int>& nums) {
        int res=nums[0];
        for(int i=1;i<size(nums);i++){
            res=res>nums[i]?nums[i]:res;
        }
        return res;
    }
};
