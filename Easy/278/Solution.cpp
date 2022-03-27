// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        //initialize the variables
        int start = 0, end = n, result = 0;
        
        //calculating the mid point
        int mid = start + (end-start)/2;
        
        //run the loop till start exceeds the end
        while(start<=end)
        {
            //checking if the mid version of product is first bad version
            if(isBadVersion(mid)==true)
            {
                result = mid;
                end = mid -1;
            }
            //it will divide the array into subarray and new start index will be first position after mid index
            else{
                start = mid + 1;
            }
            
            //calculating the new mid after new start or new end value of index
            mid = start + (end-start)/2;
        }
        
        return result;
    }

};
