class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //creation of the vector
        vector<int> v;
        
        //initialize the 2 pointer variable for traversing
        int l = 0, r = numbers.size() - 1;
        
        //logic as per asked in the problem
        while(l < r)
        {
            if(numbers[l] + numbers[r] == target)
            {
                v.push_back(l+1);
                v.push_back(r+1);
                return v;
            }
            else if(numbers[l] + numbers[r] < target)
                l++;
            else
                r--;
        }
        return v;
    }
};
