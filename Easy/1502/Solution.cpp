class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        
        //sorting the vector in ascending order
        sort(arr.begin(), arr.end(), greater<int>());
        
        //initialize the difference as per the 1st and 2nd index of the vector
        int diffe = arr[0] - arr[1];
        
        //traversing the vector and checking the condition for Arithmetic Progression by checking the difference between consecutive indexes
        for(int i=1; i<arr.size()-1; i++)
        {
            if(diffe != (arr[i]-arr[i+1]))
            {
                return false;
            }
        }
        
        return true;
        
    }
};
