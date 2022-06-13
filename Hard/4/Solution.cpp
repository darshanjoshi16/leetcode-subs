class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int n1 = nums1.size();
        
        int n2 = nums2.size();
        
        int low = 0;
        
        int high = n1;
        
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            
            int cut1 = mid;
            
            int cut2 = (n1 + n2 + 1) / 2 - cut1;
            
            int left1 = INT_MIN;
            
            int left2 = INT_MIN;
            
            int right1 = INT_MAX;
            
            int right2 = INT_MAX;
            
            if(cut1 > 0)
            {
                left1 = nums1[cut1 - 1];
            }
            
            if(cut2 > 0)
            {
                left2 = nums2[cut2 - 1];
            }
            
            if(cut1 < n1)
            {
                right1 = nums1[cut1];
            }
            
            if(cut2 < n2)
            {
                right2 = nums2[cut2];
            }
            
            if(left1 <= right2 && left2 <= right1)
            {
                if((n1 + n2) % 2 == 0)
                {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
                else
                {
                    return max(left1, left2);
                }
            }
            else if(left1 >= right2)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        return 0.0;
    }
};
