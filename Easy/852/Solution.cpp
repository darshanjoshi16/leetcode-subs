class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start=0;
        int end=arr.size();
        int mid;
        while(start <= end){
            mid=(start+end)/2;
            
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
                return mid;
            if(arr[mid] < arr[mid-1])
                end=mid;
            else start=mid;
        }
        return -1;
    }
};
