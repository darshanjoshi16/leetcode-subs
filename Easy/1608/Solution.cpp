class Solution {
public:
    int func(int mid, vector<int>nums){
        int count = 0;
            
        for(int j = 0; j<nums.size(); j++){
            if(nums[j]>=mid){
                count++;
            }
        }
        
        return count;
    }
    
    int specialArray(vector<int>& nums) {
        int low = 1, high = nums.size();
        
        while(low<=high){
            int mid = low + (high-low)/2;
            int count = func(mid, nums);
            
            if(count==mid)return mid;
            
            else if(count>mid){
                low = mid+1;
            }
            
            else{
                high = mid-1;
            }
        }
        
        return -1;
    }
};
