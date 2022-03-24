class Solution {
public:
  
  //creating the vector array of integer datatype using parameters of vector integer types and target integer variable as parameters
    vector<int> twoSum(vector<int>& nums, int target) {
       
      //it creates the unoordered mapping values of integer to integer 
        unordered_map<int, int> m;
        
      //it runs the loop from beginning to size of vector arraysize of nums parameter 
        for(int i = 0; i < nums.size(); i++){
          
          //if the mapping of ith index is > 0 and mapping of the index i-1 is not same as i then it will return the current mapped index and current value of i
            if(m[nums[i]] > 0 && m[nums[i]] - 1 != i) return{m[nums[i]] - 1, i};
            
          //it will change mapping of target-num of ith index to one index forward
            m[target-nums[i]] = i+1;
        }
        
      //it returns the index of the num
        return {-1,-1};
    }
        
    };
