class NumArray {
public:
      vector <int> copy;
    NumArray(vector<int>& nums) {
        
        for (auto i: nums)
             copy.push_back (i);
    }
    
    int sumRange(int left, int right) {
        
         int ans=0;
        for (int i=left; i<= right; i++){
            
            ans+= copy[i];
        }
        
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
