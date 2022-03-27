class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        //initialize the two variable for two pointer approach
        int i=0,j=0;
        
        //sorting both the array in the ascending order because it will help in traversing
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        //creating a temporary vector to store the result
        vector <int> result;
        
        //now we will traverse the arrays with help of both pointer and we will compare both array's elements
        while((i<nums1.size()&&(j<nums2.size())))
        {
            //if the element of i is greater then it will add the count of j otherwise it will increase count of i
            if(nums1[i]>nums2[j])
            {
                j++;
            }
            else if(nums2[j]>nums1[i])
            {
                i++;
            }
            
            //it will performing the operation when the elements are matching in both arrays.
            //it will add element into resultant vector
            else{
                result.push_back(nums1[i]);
                i++;
                j++;
            }
            
        }
       return result; 
    }
};
