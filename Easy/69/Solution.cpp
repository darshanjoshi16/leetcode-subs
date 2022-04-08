class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;
        while(l < r)
        {
            double mid = (l + r) / 2;
            if(mid * mid > x)
                r = mid -　1;
            else
                l = mid + 1;
        }
        if(1ll*l * l > x)
            return l - 1; 
        return l;
    }
};
