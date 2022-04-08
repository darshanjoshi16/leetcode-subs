class Solution {
    
    
bool binarysearch(int num,long long low, long long high)
{
    while(low<=high)
    {
        long long mid = (low+high)/2;
        if(mid*mid == num)
            return true;
        else if(mid*mid > num)
            high = mid-1;
        else
            low = mid+1;
    }
    return false;
}

public:
    bool isPerfectSquare(int num) {
        long long low = 1;
        long long high = num;
        return binarysearch(num,low,high);
    }
};
