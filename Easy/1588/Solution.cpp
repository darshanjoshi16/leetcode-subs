class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) 
    {
        //resultant initialization
        int res=0;
        
        //traversing the vector for the whole size
        for(int i=0;i<arr.size();i++)
        {
            //logic for the summation of odd length arrays
            int total = (arr.size()-i)*(i+1);
            int odd = (total+1)/2;
            res += odd * arr[i];
        }
    return res;    
    }
};
