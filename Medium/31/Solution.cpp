class Solution {
public:
    //Check from max index of the vector which is right to left for any position for while nums[j-1]<nums[j]
    void nextPermutation(vector<int>& nums) {
        // declaring j variable so as to store position where the condition is true;
        int j =0, n = nums.size()-1;
        for(j=n;j>0;j--){
            if(nums[j]>nums[j-1]){
                break;
            }
        }
        // This case comes when the array is sorted in reverse order in that cause we directly sort it in 
        // increasing order.
        if(j <=0){
            sort(nums.begin(), nums.end());
            return;
        }
        // Do the opertion move from right to left and find any number greater that nums[j] and then 
        // swap it and sort from that position.
        for(int k = n;k>=0;k--){
            if(nums[k]>nums[j-1]){
                swap(nums[k], nums[j-1]);
                sort(nums.begin()+j, nums.end());
                break;
            }
        }
    }
};
