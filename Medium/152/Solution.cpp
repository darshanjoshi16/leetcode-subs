class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0],lo=0,hi=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            lo=(lo?lo:1)*nums[i];       //keep checking for product from left
            hi=(hi?hi:1)*nums[n-i-1];  // keep checking for product form right
            res=max(res,max(lo,hi));  //  update the result accordingly
        }
        return res;
    }
};
