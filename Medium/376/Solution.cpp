class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==1){
            return 1;
        }
        int i=1;
        while(nums[0]==nums[i]){
            if(i>=nums.size()-1)
                return 1;
            i++;
        }
        int cnt=2;
        int dir = nums[i]-nums[0]>0?1:-1; //direction
        
        for(i=2;i<nums.size();i++){
            if((nums[i]-nums[i-1]>0 && dir==-1) || (nums[i]-nums[i-1]<0 && dir==1)){
                cnt++;     //each time the direction and difference of the current and previous element mismatches , 
                dir*=-1;   //indicates it will form a wiggle subsequence.
            }
        }
        return cnt;
    }
};
