class Solution {
public:
    
//Binary search for searching larger number than for every value in nums1, and since the array is 
// sorted in decreasing order so the max value found for nums1[i] would be max for that value i.e., (j-i) and thus we need find maxDist for nums1, nums2
int binarySearch(vector<int>& nums1, vector<int>& nums2, int val){
        int ans = -1, start = 0, end = nums2.size()-1;
            while(start <= end){
                int mid = start+(end-start)/2;
                if(val <= nums2[mid]){
                    ans = mid;
                    start = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
        return ans;
    }
    int maxDistance(vector<int>& num1, vector<int>& num2) {
        int maxDist = 0;
        int ans = -1;
        for(int i=0;i<num1.size();i++){
            ans = binarySearch(num1, num2, num1[i]);
            if(ans != -1)
                maxDist = max(maxDist, ans-i);
        }
        return maxDist;
    }
};
