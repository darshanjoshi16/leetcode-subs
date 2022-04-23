class Solution {
public:
    
int maxSubarraySumCircular(vector<int>& arr) {
        int maxx = INT_MIN, minn = INT_MAX, sum =0;
        int totalsum = 0, curmin = 0, curmax = 0, n = arr.size();
        for(int i=0; i< n;  i++){
            curmax += arr[i];
            maxx = max(maxx, curmax);
            if(curmax < 0)curmax  = 0;
            curmin += arr[i];
            minn = min(curmin, minn);
            if(curmin > 0)curmin = 0;
            sum+= arr[i];
            // cout<< curmax << " " << maxx <<  " " << curmin << " " << minn << " "<< sum << "\n";
        }
        if( minn == sum){
            return maxx;
        }
        else{
            return max(maxx, sum - minn);
        }
    }
};
