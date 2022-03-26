class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        //we will initialize the variable which will traverse through the both vectors and merged vectors
        int i = m - 1, j = n - 1, k = m + n - 1;
        
        //we are traversing the loop for vectors in the reverse manner
        while(i>=0 && j>=0)
        {
            //if the value of ith index in nums1 is more than jth index in nums2 than it will assign the value to kth index in the merged vectors named nums otherwise it will assign value of jth index
            //we are also reducing the value of i, j and k as per the assignment occurs
            if(nums1[i]>nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
               
        }
        
        //for nums1 vector logic
        while(i>=0)
        {
            nums1[k--]=nums1[i--];
        }
        
        //for nums2 vector logic
        while(j>=0)
        {
            nums1[k--]= nums2[j--];
        }
};
};
