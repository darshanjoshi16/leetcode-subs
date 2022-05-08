class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        //double pointer , right find a odd number and left find a even number than swap them;
        int left=0;
        int right=nums.size()-1;
        while(left<right){
            for(; left<right ; left++){
                if(nums[left] % 2 ==1){
                    break;
                }
            }
            for(; right>left ; right--){
                if(nums[right] %2==0){
                    break;
                }
            }
            swap(nums[left],nums[right]);
        }
        return nums;
        
    } 
};
