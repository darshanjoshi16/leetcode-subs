class Solution {
public:
    bool canJump(vector<int>& nums) {
        int j=0,maxnum=0;
        if(nums.size()==1)
            return true;
        for(int i=0;i<nums.size()-1;i++){
            j=i+nums[i]; //j denotes the end points of each nums[i].
            maxnum = max(j,maxnum);  //maxnum denotes the farthest we can go.
            //cout<<i<<" "<<j<<" "<<maxnum<<endl;
            if(maxnum>=nums.size()-1) //if maxnum becomes >= last index means we reached our destination.
                return true;
            if(nums[i]==0 && maxnum==i){ //if nums[i] becomes 0 and maxnum is also at that index, 
                break;                   //this we cannot go further than this index.
            }
        }
        return false;
    }
};
